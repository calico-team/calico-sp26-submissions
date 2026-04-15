def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    # YOUR CODE HERE
    U = N + M - 1
    V = N + M - 1
    SHIFT = M - 1

    cnt = [[0] * V for _ in range(U)]
    buckets = [[] for _ in range(U)]

    for r in range(N):
        row = GRID[r]
        for c in range(M):
            if row[c] == '-':
                u = r + c
                v = r - c + SHIFT
                cnt[u][v] = 1
                buckets[u].append((v, r, c))

    ps = [[0] * (V + 1) for _ in range(U + 1)]
    for u in range(U):
        ps_row = ps[u + 1]
        prev_row = ps[u]
        cnt_row = cnt[u]
        running = 0
        for v in range(V):
            running += cnt_row[v]
            ps_row[v + 1] = prev_row[v + 1] + running

    def rect_count(u0, v0, D):
        u1 = u0 + D
        v1 = v0 + D
        return (
            ps[u1 + 1][v1 + 1]
            - ps[u0][v1 + 1]
            - ps[u1 + 1][v0]
            + ps[u0][v0]
        )

    def find_window(D):
        max_u0 = U - D
        max_v0 = V - D
        for u0 in range(max_u0):
            u1 = u0 + D
            ps_u0 = ps[u0]
            ps_u1 = ps[u1 + 1]
            for v0 in range(max_v0):
                v1 = v0 + D
                total = ps_u1[v1 + 1] - ps_u0[v1 + 1] - ps_u1[v0] + ps_u0[v0]
                if total >= K:
                    return u0, v0
        return None

    lo, hi = 0, N + M - 2
    while lo < hi:
        mid = (lo + hi) // 2
        if find_window(mid) is not None:
            hi = mid
        else:
            lo = mid + 1

    best_D = lo
    u0, v0 = find_window(best_D)
    u1 = u0 + best_D
    v1 = v0 + best_D

    result = []
    for u in range(u0, u1 + 1):
        for v, r, c in buckets[u]:
            if v0 <= v <= v1:
                result.append((r, c))
                if len(result) == K:
                    return result

    return result


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
