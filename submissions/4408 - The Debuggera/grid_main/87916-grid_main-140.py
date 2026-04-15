import sys

import numpy as np


def l1_dist_transform(B, V):
    """D[k] = min_j B[j] + |V[j] - V[k]| for sorted distinct V."""
    K = len(V)
    if K == 1:
        return B.copy(), np.zeros(1, dtype=np.int32)
    f = np.empty(K, dtype=np.int64)
    pf = np.empty(K, dtype=np.int32)
    f[0] = B[0]
    pf[0] = 0
    for k in range(1, K):
        c1 = f[k - 1] + (V[k] - V[k - 1])
        c2 = B[k]
        if c1 <= c2:
            f[k] = c1
            pf[k] = pf[k - 1]
        else:
            f[k] = c2
            pf[k] = k
    b = np.empty(K, dtype=np.int64)
    pb = np.empty(K, dtype=np.int32)
    b[-1] = B[-1]
    pb[-1] = K - 1
    for k in range(K - 2, -1, -1):
        c1 = b[k + 1] + (V[k + 1] - V[k])
        c2 = B[k]
        if c1 <= c2:
            b[k] = c1
            pb[k] = pb[k + 1]
        else:
            b[k] = c2
            pb[k] = k
    D = np.minimum(f, b)
    parent = np.empty(K, dtype=np.int32)
    for k in range(K):
        if f[k] <= b[k]:
            parent[k] = pf[k]
        else:
            parent[k] = pb[k]
    return D, parent


def solve_one(A):
    A = [int(x) for x in A]
    n = len(A)
    if n == 0:
        return []
    V = sorted(set(A))
    K = len(V)
    Vnp = np.array(V, dtype=np.int64)
    Anp = np.array(A, dtype=np.int64)

    dp = np.abs(Vnp - Anp[0])
    parent_rows = []

    for i in range(1, n):
        D, par = l1_dist_transform(dp, Vnp)
        dp = D + np.abs(Vnp - Anp[i])
        parent_rows.append(par)

    k = int(np.argmin(dp))
    b_idx = [0] * n
    b_idx[-1] = k
    for i in range(n - 2, -1, -1):
        k = int(parent_rows[i][k])
        b_idx[i] = k
    return [V[j] for j in b_idx]


def main():
    data = sys.stdin.read().split()
    it = iter(data)
    T = int(next(it))
    out_lines = []
    for _ in range(T):
        N = int(next(it))
        A = [next(it) for _ in range(N)]
        b = solve_one(A)
        out_lines.append(" ".join(str(x) for x in b))
    sys.stdout.write("\n".join(out_lines) + "\n")


if __name__ == "__main__":
    main()
