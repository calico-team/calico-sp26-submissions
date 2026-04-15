johnny_d_lecture = True
import sys
import numpy as np

def solve(N, M, K, GRID):
    empty = []
    for r in range(N):
        row = GRID[r]
        for c in range(M):
            if row[c] == '-':
                empty.append((r, c))

    if K == 1:
        return [empty[0]]

    U = N + M - 1
    V = N + M - 1

    seat = np.zeros((U, V), dtype=np.int32)
    for (r, c) in empty:
        seat[r + c, r - c + M - 1] = 1

    # 2D prefix sum
    PS = np.zeros((U + 1, V + 1), dtype=np.int32)
    PS[1:, 1:] = seat.cumsum(axis=0).cumsum(axis=1)

    def feasible(D):
        # window size (D+1) x (D+1)
        w = D + 1
        if w > U and w > V:
            return PS[U, V] >= K
        uw = min(w, U)
        vw = min(w, V)
        # sum over all (uw x vw) windows
        # windows[i,j] = PS[i+uw, j+vw] - PS[i, j+vw] - PS[i+uw, j] + PS[i, j]
        windows = (PS[uw:, vw:] - PS[:-uw if uw else None, vw:]
                   - PS[uw:, :-vw if vw else None] + PS[:-uw if uw else None, :-vw if vw else None])
        return bool((windows >= K).any())

    lo, hi = 0, U + V
    while lo < hi:
        mid = (lo + hi) // 2
        if feasible(mid):
            hi = mid
        else:
            lo = mid + 1
    D = lo

    L = len(empty)
    for i in range(L - K + 1):
        group = empty[i:i + K]
        us = [r + c for r, c in group]
        vs = [r - c for r, c in group]
        md = max(max(us) - min(us), max(vs) - min(vs))
        if md <= D:
            return group

    # Greedy fallback
    for i in range(L):
        r0, c0 = empty[i]
        chosen = [(r0, c0)]
        umin = umax = r0 + c0
        vmin = vmax = r0 - c0
        for j in range(i + 1, L):
            r, c = empty[j]
            u = r + c; v = r - c
            nu_min = umin if u >= umin else u
            nu_max = umax if u <= umax else u
            nv_min = vmin if v >= vmin else v
            nv_max = vmax if v <= vmax else v
            if max(nu_max - nu_min, nv_max - nv_min) <= D:
                chosen.append((r, c))
                umin, umax, vmin, vmax = nu_min, nu_max, nv_min, nv_max
                if len(chosen) == K:
                    return chosen
    return empty[:K]


def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    T = int(data[idx]); idx += 1
    out = []
    for _ in range(T):
        N = int(data[idx]); M = int(data[idx+1]); K = int(data[idx+2]); idx += 3
        GRID = []
        for _ in range(N):
            GRID.append(data[idx].decode()); idx += 1
        for r, c in solve(N, M, K, GRID):
            out.append(f"{r} {c}")
    sys.stdout.write("\n".join(out) + "\n")


def read_your_input():
    return sys.stdin.readline


if __name__ == '__main__':
    main()


