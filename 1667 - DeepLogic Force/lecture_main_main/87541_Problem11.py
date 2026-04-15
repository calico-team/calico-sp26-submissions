johnny_d_lecture = True
import sys


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

    row_ps = [[0] * (V + 1) for _ in range(U)]
    for (r, c) in empty:
        u = r + c
        v = r - c + M - 1
        row_ps[u][v + 1] = 1  
    for u in range(U):
        rp = row_ps[u]
        acc = 0
        for j in range(1, V + 1):
            acc += rp[j]
            rp[j] = acc


    PS = [[0] * (V + 1)]
    for u in range(U):
        prev = PS[u]
        rp = row_ps[u]
        cur = [prev[j] + rp[j] for j in range(V + 1)]
        PS.append(cur)

    def feasible(D):
        w = D + 1
        for u0 in range(U):
            u2 = u0 + w
            if u2 > U:
                u2 = U
            top = PS[u0]
            bot = PS[u2]
            if w >= V:
                if bot[V] - top[V] >= K:
                    return True
                continue
            limit = V - w
            for v0 in range(limit + 1):
                if (bot[v0 + w] - top[v0 + w]) - (bot[v0] - top[v0]) >= K:
                    return True
        return False

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
        umin = umax = group[0][0] + group[0][1]
        vmin = vmax = group[0][0] - group[0][1]
        ok = True
        for k in range(1, K):
            r, c = group[k]
            u = r + c; v = r - c
            if u < umin: umin = u
            elif u > umax: umax = u
            if v < vmin: vmin = v
            elif v > vmax: vmax = v
            if umax - umin > D or vmax - vmin > D:
                ok = False
                break
        if ok:
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
            nu_min = u if u < umin else umin
            nu_max = u if u > umax else umax
            nv_min = v if v < vmin else vmin
            nv_max = v if v > vmax else vmax
            if nu_max - nu_min <= D and nv_max - nv_min <= D:
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