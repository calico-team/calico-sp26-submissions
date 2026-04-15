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

# runtime error counter: 6
# timelimit error: 0
# wrong answer counter: 1

import sys
import math
import time
import heapq
from array import array

def main():
    t0 = time.time()
    inp = sys.stdin

    line = inp.readline().split()
    N = int(line[0]); M = int(line[1]); D = int(line[2])

    if M == 0:
        sys.stdout.write(' '.join(['1']*N) + '\n0\n')
        return

    R = array('i', [0]*M)
    C = array('i', [0]*M)
    V = array('d', [0.0]*M)
    W = array('d', [0.0]*M)
    for i in range(M):
        parts = inp.readline().split()
        R[i] = int(parts[0])-1
        C[i] = int(parts[1])-1
        V[i] = float(parts[2])
        W[i] = float(parts[3])

    # Flat adjacency
    counts = array('i', [0]*N)
    for i in range(M):
        counts[R[i]] += 1
        counts[C[i]] += 1
    offsets = array('i', [0]*(N+1))
    for i in range(N):
        offsets[i+1] = offsets[i] + counts[i]
    total_adj = offsets[N]
    adj_ci = array('i', [0]*total_adj)
    adj_ov = array('i', [0]*total_adj)
    fill = array('i', [0]*N)
    for i in range(M):
        r = R[i]; c = C[i]
        p = offsets[r] + fill[r]
        adj_ci[p] = i; adj_ov[p] = c; fill[r] += 1
        p = offsets[c] + fill[c]
        adj_ci[p] = i; adj_ov[p] = r; fill[c] += 1
    del fill, counts

    LOG_MAX = math.log(1e9)
    _log = math.log; _exp = math.exp; _abs = abs

    def clamp_log(x):
        if x < 0.0: return 0.0
        if x > LOG_MAX: return LOG_MAX
        return x

    def log_to_int(x):
        if x < 0.0: x = 0.0
        elif x > LOG_MAX: x = LOG_MAX
        v = int(_exp(x) + 0.5)
        if v < 1: return 1
        if v > 1000000000: return 1000000000
        return v

    def compute_discard(a):
        pens_sum = 0.0
        if D <= 0:
            for i in range(M):
                pens_sum += W[i] * _abs(a[R[i]] * a[C[i]] - V[i]) / V[i]
            return pens_sum, []
        d = min(D, M)
        heap = []
        for i in range(M):
            p = W[i] * _abs(a[R[i]] * a[C[i]] - V[i]) / V[i]
            pens_sum += p
            if p > 0:
                if len(heap) < d:
                    heapq.heappush(heap, (p, i))
                elif p > heap[0][0]:
                    heapq.heapreplace(heap, (p, i))
        disc_sum = 0.0; ds = []
        for p, idx in heap:
            ds.append(idx); disc_sum += p
        return pens_sum - disc_sum, ds

    def var_penalty(v, a):
        start = offsets[v]; end = offsets[v+1]
        p = 0.0
        for j in range(start, end):
            ci = adj_ci[j]; ov = adj_ov[j]
            p += W[ci] * _abs(a[v] * a[ov] - V[ci]) / V[ci]
        return p

    def eval_var(v, nv, a):
        start = offsets[v]; end = offsets[v+1]
        p = 0.0
        for j in range(start, end):
            ci = adj_ci[j]; ov = adj_ov[j]
            p += W[ci] * _abs(nv * a[ov] - V[ci]) / V[ci]
        return p

    # ============================================================
    # Phase 1: Log-space weighted coordinate descent (good init)
    # ============================================================
    logV = array('d', [_log(V[i]) for i in range(M)])
    log_a = [0.0] * N

    for iteration in range(50):
        if time.time() - t0 > 1.2:
            break
        for v in range(N):
            start = offsets[v]; end = offsets[v+1]
            if start == end: continue
            num = 0.0; den = 0.0
            for j in range(start, end):
                w = W[adj_ci[j]]
                num += w * (logV[adj_ci[j]] - log_a[adj_ov[j]])
                den += w
            if den > 0:
                log_a[v] = clamp_log(num / den)

    a = [log_to_int(log_a[i]) for i in range(N)]

    # Discard + re-solve loop
    best_penalty, best_ds_list = compute_discard(a)
    best_ds = set(best_ds_list)
    best_a = a[:]

    for outer in range(5):
        if time.time() - t0 > 2.0:
            break
        log_a = [clamp_log(_log(max(1, ai))) for ai in a]
        for iteration in range(30):
            if time.time() - t0 > 2.0:
                break
            for v in range(N):
                start = offsets[v]; end = offsets[v+1]
                if start == end: continue
                num = 0.0; den = 0.0
                for j in range(start, end):
                    ci = adj_ci[j]
                    if ci in best_ds: continue
                    w = W[ci]
                    num += w * (logV[ci] - log_a[adj_ov[j]])
                    den += w
                if den > 0:
                    log_a[v] = clamp_log(num / den)
        a = [log_to_int(log_a[i]) for i in range(N)]
        pen, ds_list = compute_discard(a)
        if pen < best_penalty - 1e-9:
            best_penalty = pen; best_a = a[:]; best_ds = set(ds_list)
        else:
            break

    del logV

    # ============================================================
    # Phase 2: Local search with rich candidate generation
    # For each var: try ±1..3, all breakpoints V[ci]/a[other],
    # and weighted median
    # ============================================================
    a = best_a[:]

    for local_iter in range(20):
        if time.time() - t0 > 8.5:
            break
        improved = False

        for v in range(N):
            if time.time() - t0 > 8.5:
                break
            start = offsets[v]; end = offsets[v+1]
            if start == end: continue

            old_val = a[v]
            old_pen = 0.0
            for j in range(start, end):
                ci = adj_ci[j]; ov = adj_ov[j]
                old_pen += W[ci] * _abs(old_val * a[ov] - V[ci]) / V[ci]

            # Generate candidates
            cands = set()
            for delta in (-3,-2,-1,1,2,3):
                nv = old_val + delta
                if 1 <= nv <= 1000000000:
                    cands.add(nv)

            # Breakpoints + weighted median
            points = []
            for j in range(start, end):
                ci = adj_ci[j]; ao = a[adj_ov[j]]
                if ao > 0:
                    ideal = V[ci] / ao
                    fl = max(1, int(ideal))
                    cands.add(fl)
                    if fl + 1 <= 1000000000: cands.add(fl + 1)
                    # Weight for weighted median: W[ci]*ao/V[ci]
                    points.append((ideal, W[ci] * ao / V[ci]))

            # Weighted median
            if points:
                points.sort()
                total_w = 0.0
                for _, w in points:
                    total_w += w
                half = total_w * 0.5
                cum = 0.0
                for ideal, w in points:
                    cum += w
                    if cum >= half:
                        fl = max(1, int(ideal))
                        cands.add(fl)
                        if fl + 1 <= 1000000000: cands.add(fl + 1)
                        if fl > 1: cands.add(fl - 1)
                        break

            cands.discard(old_val)

            best_local = old_val
            best_local_pen = old_pen
            for nv in cands:
                p = 0.0
                for j in range(start, end):
                    ci = adj_ci[j]; ov = adj_ov[j]
                    p += W[ci] * _abs(nv * a[ov] - V[ci]) / V[ci]
                if p < best_local_pen - 1e-12:
                    best_local_pen = p
                    best_local = nv

            if best_local != old_val:
                a[v] = best_local
                improved = True

        if not improved:
            break

    pen, ds_list = compute_discard(a)
    if pen < best_penalty:
        best_a = a; best_ds_list = ds_list; best_penalty = pen

    # Output
    discard_1indexed = sorted(i+1 for i in best_ds_list)
    sys.stdout.write(' '.join(map(str, best_a)))
    sys.stdout.write('\n')
    sys.stdout.write(str(len(discard_1indexed)))
    if discard_1indexed:
        sys.stdout.write(' ')
        sys.stdout.write(' '.join(map(str, discard_1indexed)))
    sys.stdout.write('\n')

if __name__ == '__main__':
    main()
