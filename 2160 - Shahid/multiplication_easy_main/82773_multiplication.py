import sys
import math
import numpy as np
from scipy import sparse
from scipy.sparse.linalg import lsqr


def solve():
    data = sys.stdin.buffer.read().split()
    idx = 0
    N = int(data[idx]); idx += 1
    M = int(data[idx]); idx += 1
    D = int(data[idx]); idx += 1

    R = np.empty(M, dtype=np.int32)
    C_arr = np.empty(M, dtype=np.int32)
    V = np.empty(M, dtype=np.float64)
    W_arr = np.empty(M, dtype=np.float64)

    for i in range(M):
        R[i] = int(data[idx]) - 1; idx += 1
        C_arr[i] = int(data[idx]) - 1; idx += 1
        V[i] = float(data[idx]); idx += 1
        W_arr[i] = float(data[idx]); idx += 1

    # Step 1: Log-space weighted least squares
    # Model: x_R + x_C = log(V), weighted by W
    row_indices = np.concatenate([np.arange(M), np.arange(M)])
    col_indices = np.concatenate([R, C_arr])
    values = np.concatenate([W_arr, W_arr])

    A = sparse.csr_matrix((values, (row_indices, col_indices)), shape=(M, N))
    b = W_arr * np.log(V)

    result = lsqr(A, b, iter_lim=5000)
    x = result[0]

    a = np.maximum(1, np.minimum(10**9, np.round(np.exp(x)))).astype(np.int64)

    # Step 2: Build adjacency lists for coordinate descent
    adj_constraints = [[] for _ in range(N)]
    adj_partners = [[] for _ in range(N)]
    for i in range(M):
        adj_constraints[R[i]].append(i)
        adj_partners[R[i]].append(C_arr[i])
        adj_constraints[C_arr[i]].append(i)
        adj_partners[C_arr[i]].append(R[i])

    adj_c = [np.array(x, dtype=np.int32) for x in adj_constraints]
    adj_p = [np.array(x, dtype=np.int32) for x in adj_partners]

    # Step 3: Coordinate descent refinement
    active = np.ones(M, dtype=bool)  # all constraints active initially

    for outer in range(2):  # two rounds: before and after discarding
        for iteration in range(10):
            changed = False
            for j in range(N):
                if len(adj_c[j]) == 0:
                    continue

                ci = adj_c[j]
                pi = adj_p[j]

                # Only consider active constraints
                mask = active[ci]
                if not np.any(mask):
                    continue

                ci_active = ci[mask]
                pi_active = pi[mask]
                v_j = V[ci_active]
                w_j = W_arr[ci_active]
                a_p = a[pi_active].astype(np.float64)
                a_p = np.maximum(a_p, 1.0)

                # Weighted median: minimize sum w_k * a_p_k / v_k * |a_j - v_k/a_p_k|
                targets = v_j / a_p
                weights = w_j * a_p / v_j

                sorted_idx = np.argsort(targets)
                targets_sorted = targets[sorted_idx]
                weights_sorted = weights[sorted_idx]
                cum_w = np.cumsum(weights_sorted)
                half = cum_w[-1] / 2.0
                median_idx = int(np.searchsorted(cum_w, half))
                if median_idx >= len(targets_sorted):
                    median_idx = len(targets_sorted) - 1

                optimal = targets_sorted[median_idx]

                cand_floor = max(1, min(10**9, int(math.floor(optimal))))
                cand_ceil = max(1, min(10**9, int(math.ceil(optimal))))

                pen_floor = np.sum(w_j * np.abs(cand_floor * a_p - v_j) / v_j)
                pen_ceil = np.sum(w_j * np.abs(cand_ceil * a_p - v_j) / v_j)

                new_val = cand_floor if pen_floor <= pen_ceil else cand_ceil
                if new_val != a[j]:
                    changed = True
                    a[j] = new_val

            if not changed:
                break

        # After first round, discard top D constraints and re-optimize
        if outer == 0 and D > 0:
            products = a[R].astype(np.float64) * a[C_arr].astype(np.float64)
            penalties = W_arr * np.abs(products - V) / V
            penalties[~active] = -1  # already inactive
            discard_count = min(D, M)
            top_d = np.argsort(penalties)[-discard_count:]
            active[top_d] = False

    # Step 4: Final penalty computation and discard selection
    products = a[R].astype(np.float64) * a[C_arr].astype(np.float64)
    penalties = W_arr * np.abs(products - V) / V

    if D > 0:
        discard_count = min(D, M)
        discard_indices = np.argsort(penalties)[-discard_count:]
        # Only discard those with positive penalty
        discard_indices = discard_indices[penalties[discard_indices] > 0]
        discard_1indexed = sorted(discard_indices + 1)
        print(' '.join(map(str, a)))
        print(str(len(discard_1indexed)) + (' ' + ' '.join(map(str, discard_1indexed)) if discard_1indexed else ''))
    else:
        print(' '.join(map(str, a)))
        print('0')


solve()
