def solve(N, M, K, GRID):
    """ N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats. """

    D = N + M - 1
    A = [bytearray(D) for _ in range(D)]

    for r in range(N):
        row = GRID[r]
        for c in range(M):
            if row[c] != '-':
                continue

            u = r + c
            v = r - c + M - 1
            A[u][v] = 1

    def canDo(d):
        w = d + 1
        if w > D:
            return None
        col = [0] * D

        for u in range(w):
            src = A[u]
            for v in range(D):
                col[v] += src[v]

        crnt = sum(col[:w])
        if crnt >= K:
            return 0, 0

        lim = D - w
        for x in range(1, lim + 1):
            crnt += col[x + w - 1] - col[x - 1]
            if crnt >= K:
                return 0, x

        for y in range(1, lim + 1):
            out = A[y - 1]
            inp = A[y + w - 1]
            for v in range(D):
                col[v] += inp[v] - out[v]

            crnt = sum(col[:w])
            if crnt >= K:
                return y, 0

            for x in range(1, lim + 1):
                crnt += col[x + w - 1] - col[x - 1]
                if crnt >= K:
                    return y, x

        return None

    lo = 0
    hi = D - 1
    best = hi
    baseU = 0
    baseV = 0

    while lo <= hi:
        mid = (lo + hi) // 2
        got = canDo(mid)
        if got:
            best = mid
            baseU, baseV = got
            hi = mid - 1
        else:
            lo = mid + 1

    R = []
    u2 = baseU + best
    v2 = baseV + best

    for r in range(N):
        row = GRID[r]
        for c in range(M):
            if row[c] != '-':
                continue
            u = r + c
            v = r - c + M - 1
            if baseU <= u <= u2 and baseV <= v <= v2:
                R.append((r, c))
                if len(R) == K:
                    return R

    return R


def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        GRID = []
        for _ in range(N):
            GRID.append(input().strip())
        result = solve(N, M, K, GRID)
        for r, c in result:
            print(f"{r} {c}")


if __name__ == '__main__':
    main()
