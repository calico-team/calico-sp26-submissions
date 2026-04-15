johnny_d_lecture = True


def solve(N, M, K, GRID):
    empty = [(r, c) for r in range(N) for c in range(M) if GRID[r][c] == '-']

    if K == 1:
        return [empty[0]]

    U = N + M - 1
    V = N + M - 1
    seat = [[0] * V for _ in range(U)]
    for (r, c) in empty:
        seat[r + c][r - c + M - 1] = 1

    PS = [[0] * (V + 1) for _ in range(U + 1)]
    for i in range(U):
        for j in range(V):
            PS[i + 1][j + 1] = seat[i][j] + PS[i + 1][j] + PS[i][j + 1] - PS[i][j]

    def rect(u1, v1, u2, v2):
        if u2 >= U: u2 = U - 1
        if v2 >= V: v2 = V - 1
        return PS[u2 + 1][v2 + 1] - PS[u1][v2 + 1] - PS[u2 + 1][v1] + PS[u1][v1]

    def feasible(D):
        for u0 in range(U):
            for v0 in range(V):
                if rect(u0, v0, u0 + D, v0 + D) >= K:
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

    for i in range(len(empty) - K + 1):
        group = empty[i:i + K]
        maxd = 0
        for a in range(K):
            ra, ca = group[a]
            for b in range(a + 1, K):
                rb, cb = group[b]
                d = abs(ra - rb) + abs(ca - cb)
                if d > maxd:
                    maxd = d
                    if maxd > D:
                        break
            if maxd > D:
                break
        if maxd <= D:
            return group

    for i, (r0, c0) in enumerate(empty):
        chosen = [(r0, c0)]
        for j in range(i + 1, len(empty)):
            r, c = empty[j]
            if all(abs(r - rr) + abs(c - cc) <= D for rr, cc in chosen):
                chosen.append((r, c))
                if len(chosen) == K:
                    return chosen
    return empty[:K]


def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        GRID = [input().strip() for _ in range(N)]
        for r, c in solve(N, M, K, GRID):
            print(f"{r} {c}")


def read_your_input():
    import sys
    return sys.stdin.readline


if __name__ == '__main__':
    main()