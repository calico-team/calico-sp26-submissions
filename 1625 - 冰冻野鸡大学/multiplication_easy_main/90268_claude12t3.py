# WRITTEN BY CLAUDE OPUS 4.6 EXTENDED

#   /$$$$$$  /$$        /$$$$$$  /$$   /$$ /$$$$$$$  /$$$$$$$$
#  /$$__  $$| $$       /$$__  $$| $$  | $$| $$__  $$| $$_____/
# | $$  \__/| $$      | $$  \ $$| $$  | $$| $$  \ $$| $$
# | $$      | $$      | $$$$$$$$| $$  | $$| $$  | $$| $$$$$
# | $$      | $$      | $$__  $$| $$  | $$| $$  | $$| $$__/
# | $$    $$| $$      | $$  | $$| $$  | $$| $$  | $$| $$
# |  $$$$$$/| $$$$$$$$| $$  | $$|  $$$$$$/| $$$$$$$/| $$$$$$$$
#  \______/ |________/|__/  |__/ \______/ |_______/ |________/
                                                            
# (which should probably be allowed since contest ended and I have 0 clue how to do this)
# PLS NO BAN

import sys
import numpy as np
from scipy import sparse
from scipy.sparse.linalg import lsqr
import math
import time
from collections import defaultdict

def main():
    t0 = time.time()

    data = sys.stdin.buffer.read()
    all_nums = np.array(data.split(), dtype=np.float64)
    N = int(all_nums[0])
    M = int(all_nums[1])
    D = int(all_nums[2])

    rest = all_nums[3:].reshape(M, 4)
    R = (rest[:, 0] - 1).astype(np.int32)
    C = (rest[:, 1] - 1).astype(np.int32)
    V = rest[:, 2]
    W = rest[:, 3]

    log_V = np.log(V)
    WoverV = W / V

    # Build per-variable adjacency
    temp = defaultdict(list)
    for i in range(M):
        temp[R[i]].append((i, C[i]))
        temp[C[i]].append((i, R[i]))

    var_ci = [None] * N
    var_other = [None] * N
    var_vv = [None] * N
    var_wov = [None] * N

    for v in range(N):
        if v in temp:
            items = temp[v]
            ci = np.array([x[0] for x in items], dtype=np.int32)
            oi = np.array([x[1] for x in items], dtype=np.int32)
            var_ci[v] = ci
            var_other[v] = oi
            var_vv[v] = V[ci]
            var_wov[v] = WoverV[ci]
        else:
            var_ci[v] = np.array([], dtype=np.int32)
            var_other[v] = np.array([], dtype=np.int32)
            var_vv[v] = np.array([], dtype=np.float64)
            var_wov[v] = np.array([], dtype=np.float64)

    del temp

    def solve_lsq(mask=None):
        if mask is None:
            idx_arr = np.arange(M)
        else:
            idx_arr = np.where(mask)[0]
        m = len(idx_arr)
        if m == 0:
            return np.ones(N)
        row_idx = np.concatenate([np.arange(m), np.arange(m)])
        col_idx = np.concatenate([R[idx_arr], C[idx_arr]])
        weights = np.sqrt(W[idx_arr])
        vals = np.concatenate([weights, weights])
        A = sparse.csr_matrix((vals, (row_idx, col_idx)), shape=(m, N))
        b = log_V[idx_arr] * weights
        result = lsqr(A, b, atol=1e-12, btol=1e-12, iter_lim=20000)
        return result[0]

    def compute_all_penalties(a):
        return W * np.abs(a[R] * a[C] - V) / V

    def get_discard_and_penalty(penalties):
        if D > 0 and M > 0:
            d = min(D, M)
            top_d = np.argpartition(penalties, -d)[-d:]
            top_d = top_d[penalties[top_d] > 0]
            ds = set(top_d.tolist())
            total = float(np.sum(penalties)) - sum(float(penalties[j]) for j in ds)
            return total, ds
        return float(np.sum(penalties)), set()

    # Phase 1: Log-space least squares with iterative discard
    x = solve_lsq()
    a_real = np.exp(x)

    best_penalty = float('inf')
    best_a = None
    best_discard = set()

    for a_cand in [np.round(a_real), np.floor(a_real), np.ceil(a_real)]:
        a_cand = np.clip(a_cand, 1, 1e9)
        pens = compute_all_penalties(a_cand)
        pen, ds = get_discard_and_penalty(pens)
        if pen < best_penalty:
            best_penalty = pen
            best_a = a_cand.copy()
            best_discard = ds

    for it in range(8):
        if time.time() - t0 > 2.5:
            break
        mask = np.ones(M, dtype=bool)
        if best_discard:
            mask[list(best_discard)] = False
        x = solve_lsq(mask)
        a_real = np.exp(x)
        changed = False
        for a_cand in [np.round(a_real), np.floor(a_real), np.ceil(a_real)]:
            a_cand = np.clip(a_cand, 1, 1e9)
            pens = compute_all_penalties(a_cand)
            pen, ds = get_discard_and_penalty(pens)
            if pen < best_penalty - 1e-9:
                best_a = a_cand.copy()
                best_penalty = pen
                best_discard = ds
                changed = True
        if not changed:
            break

    # Phase 2: Vectorized local search
    a_current = best_a.copy()
    pens = compute_all_penalties(a_current)
    total_sum = float(np.sum(pens))

    for local_iter in range(30):
        if time.time() - t0 > 8.5:
            break
        improved = False

        for i in range(N):
            if time.time() - t0 > 8.5:
                break

            ci = var_ci[i]
            if len(ci) == 0:
                continue

            others_vals = a_current[var_other[i]]
            vv = var_vv[i]
            wov = var_wov[i]

            old_val = a_current[i]
            old_pen_sum = float(np.sum(wov * np.abs(old_val * others_vals - vv)))

            cands = set()
            for delta in [-3, -2, -1, 1, 2, 3]:
                v = old_val + delta
                if 1 <= v <= 1e9:
                    cands.add(v)

            mask_nz = others_vals > 0
            if np.any(mask_nz):
                ideals = vv[mask_nz] / others_vals[mask_nz]
                for ideal in ideals[:40]:
                    fl = max(1, math.floor(ideal))
                    ce = max(1, math.ceil(ideal))
                    if fl <= 1e9:
                        cands.add(fl)
                    if ce <= 1e9:
                        cands.add(ce)

            cands.discard(old_val)
            if not cands:
                continue

            cands_arr = np.array(list(cands))
            products = np.outer(cands_arr, others_vals)
            pen_sums = (wov[np.newaxis, :] * np.abs(products - vv[np.newaxis, :])).sum(axis=1)

            best_idx = np.argmin(pen_sums)
            if pen_sums[best_idx] < old_pen_sum - 1e-12:
                new_val = cands_arr[best_idx]
                a_current[i] = new_val
                new_pens = wov * np.abs(new_val * others_vals - vv)
                total_sum += float(np.sum(new_pens)) - old_pen_sum
                pens[ci] = new_pens
                improved = True

        if not improved:
            break

    # Final discard
    pens = compute_all_penalties(a_current)
    pen_final, ds_final = get_discard_and_penalty(pens)

    if pen_final < best_penalty:
        best_a = a_current
        best_discard = ds_final

    # Output
    a_final = np.clip(best_a, 1, 10**9).astype(np.int64)
    pens_out = compute_all_penalties(a_final.astype(np.float64))
    _, ds_out = get_discard_and_penalty(pens_out)

    out = []
    out.append(' '.join(str(x) for x in a_final))
    discard_1indexed = sorted([int(x) + 1 for x in ds_out])
    out.append(str(len(discard_1indexed)) + (' ' + ' '.join(str(x) for x in discard_1indexed) if discard_1indexed else ''))
    sys.stdout.write('\n'.join(out) + '\n')

if __name__ == '__main__':
    main()
