def solve(N, M, D, cells):
    """
    Return a tuple (A, discards) where:
      A: list of N integers in [1, 10^9]
      discards: list of at most D distinct 1-indexed cell indices to discard

    The discards output line will begin with t, the number of discarded
    cells, followed by those t indices; t is computed and written for
    you in main().

    N: length of the array A
    M: number of cells
    D: maximum number of cells you may discard
    cells: list of M tuples (R, C, V, W); for cell k (1-indexed), the product
           A[R] * A[C] should be close to the target V, with weight W
    """
    # YOUR CODE HERE
    return [1 for _ in range(N)], []


def main():
    N, M, D = map(int, input().split())
    cells = []
    for _ in range(M):
        R, C, V, W = map(int, input().split())
        cells.append((R, C, V, W))
    A, discards = solve(N, M, D, cells)
    print(' '.join(str(x) for x in A))
    print(' '.join(str(x) for x in [len(discards)] + list(discards)))


if __name__ == '__main__':
    main()


import math
import numpy as np


def solve(N, M, D, cells):
    """
    Return a tuple (A, discards) where:
      A: list of N integers in [1, 10^9]
      discards: list of at most D distinct 1-indexed cell indices to discard

    The discards output line will begin with t, the number of discarded
    cells, followed by those t indices; t is computed and written for
    you in main().

    N: length of the array A
    M: number of cells
    D: maximum number of cells you may discard
    cells: list of M tuples (R, C, V, W); for cell k (1-indexed), the product
           A[R] * A[C] should be close to the target V, with weight W
    """
    if M == 0:
        return [1] * N, []

    R = np.array([c[0] for c in cells], dtype=np.int32)
    C = np.array([c[1] for c in cells], dtype=np.int32)
    V = np.array([c[2] for c in cells], dtype=np.float64)
    W = np.array([c[3] for c in cells], dtype=np.float64)
    LV = np.log(V)

    # Scale itr and number of pre-discard candidates to stay within 10s
    if M < 50000:
        itr, num_pre = 500, min(D, 20)
    elif M < 500000:
        itr, num_pre = 200, min(D, 10)
    elif M < 1000000:
        itr, num_pre = 100, min(D, 5)
    else:
        itr, num_pre = 60, min(D, 2)

    bp = float('inf')
    b_a = None
    b_d = None

    def t_solution(p_d_s):
        nonlocal bp, b_a, b_d
        pn, A, disc = _optmize(N, M, D, R, C, V, W, LV, p_d_s, itr)
        if pn < bp:
            bp, b_a, b_d = pn, A, disc

    # Attempt 1: no pre-discards, let coord descent find a good solution
    t_solution(set())

    # Attempt 2+: pre-discard each of the top num_pre highest-weight constraints
    # before optimizing — prevents a single heavy outlier from warping the whole fit
    top_indices = np.argpartition(-W, min(num_pre, M - 1))[:num_pre]
    for k in top_indices:
        t_solution({int(k)})

    return b_a, b_d


# ---------------------------------------------------------------------------
# Internal helpers
# ---------------------------------------------------------------------------

def _run_co_de(N, Ra, Ca, LVa, Wa, total_w, itr=200, alha=0.5):
    """
    Damped Jacobi coordinate descent in log-space.

    We want b[r] + b[c] ≈ log(V) for each constraint.
    Update rule:  b[r] ← weighted_avg_c( log(V) - b[c] )
    Damping (α=0.5) prevents oscillation on odd-cycle graphs.
    Uses numpy.bincount for O(M) scatter — fast enough for M=2e6.
    """
    b = np.zeros(N + 1, dtype=np.float64)
    msk = total_w > 0

    for _ in range(itr):
        b_old = b[msk].copy()

        c_r = Wa * (LVa - b[Ca])
        c_c = Wa * (LVa - b[Ra])
        n_num = (np.bincount(Ra, weights=c_r, minlength=N + 1) +
                   np.bincount(Ca, weights=c_c, minlength=N + 1))

        b_new = b.copy()
        b_new[msk] = n_num[msk] / total_w[msk]
        b = alha * b_new + (1.0 - alha) * b

        if np.max(np.abs(b[msk] - b_old)) < 1e-9:
            break

    return b


def _b_to_A(b, N):
    """Convert log-space values to integer array (1-indexed, prepend dummy 0)."""
    vals = np.exp(np.clip(b[1:], -20.7, 20.7))
    vals = np.clip(vals, 1.0, 1e9)
    a = np.clip(np.round(vals).astype(np.int64), 1, 10**9)
    return np.concatenate([[0], a])  # index-0 unused


def _optmize(N, M, D, R, C, V, W, LV, p_d_s, itr):
    """
    Run coord descent excluding p_d_s constraints, then greedily
    select the remaining D - |p_d_s| worst constraints to discard.
    Returns (plty, A_array, sorted_1indexed_discards).
    """
    d_mask = np.zeros(M, dtype=bool)
    for i in p_d_s:
        d_mask[i] = True

    acte = ~d_mask
    Ra, Ca, LVa, Wa = R[acte], C[acte], LV[acte], W[acte]

    total_w = (np.bincount(Ra, weights=Wa, minlength=N + 1) +
               np.bincount(Ca, weights=Wa, minlength=N + 1))

    b = _run_co_de(N, Ra, Ca, LVa, Wa, total_w, itr=itr)
    a = _b_to_A(b, N)

    rening_D = max(0, D - len(p_d_s))

    # Compute plty for every acte constraint
    prod = a[R[acte]].astype(np.float64) * a[C[acte]].astype(np.float64)
    pens_active = W[acte] * np.abs(prod - V[acte]) / V[acte]

    ps_full = np.zeros(M, dtype=np.float64)
    ps_full[acte] = pens_active

    # Pick top rening_D acte constraints to additionally discard
    active_idx = np.where(acte)[0]
    if rening_D > 0 and rening_D < len(pens_active):
        op_etra = active_idx[np.argpartition(-pens_active, rening_D)[:rening_D]]
    elif rening_D >= len(pens_active):
        op_etra = active_idx
    else:
        op_etra = np.array([], dtype=int)

    all_dard_0 = p_d_s | set(op_etra.tolist())

    final_active = np.ones(M, dtype=bool)
    for i in all_dard_0:
        final_active[i] = False

    plty = float(np.sum(ps_full[final_active]))
    dirds_1indexed = sorted([i + 1 for i in all_dard_0])

    return plty, a[1:].tolist(), dirds_1indexed


def main():
    import sys
    data = sys.stdin.buffer.read().split()
    idx = 0
    N = int(data[idx]); idx += 1
    M = int(data[idx]); idx += 1
    D = int(data[idx]); idx += 1
    cells = []
    for _ in range(M):
        R = int(data[idx]); idx += 1
        C = int(data[idx]); idx += 1
        V = int(data[idx]); idx += 1
        W = int(data[idx]); idx += 1
        cells.append((R, C, V, W))
    A, discards = solve(N, M, D, cells)
    print(' '.join(str(x) for x in A))
    print(' '.join(str(x) for x in [len(discards)] + list(discards)))


if __name__ == '__main__':
    main()

