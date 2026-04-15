def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    # YOUR CODE HERE
    johnny_d_lecture = 0

    SHIFT = M - 1
    U = N + M - 1
    V = N + M - 1

    seats = []
    row_seats = [[] for _ in range(N)]

    for r in range(N):
        for c in range(M):
            if GRID[r][c] =='-':
                row_seats[r].append(c)

    aura = {}
    for r in range(N):
        occ_prefix = [0] * (M + 1)
        for c in range(M):
            occ_prefix[c + 1] = occ_prefix[c] + (1 if GRID[r][c] =='#' else 0)
        total_occ = occ_prefix[M]
        for c in row_seats[r]:
            left_occ = occ_prefix[c]
            right_occ = total_occ - occ_prefix[c + 1]
            aura[(r, c)] = min(left_occ, right_occ)

    cnt = [[0] * V for _ in range(U)]
    buckets = [[] for _ in range(U)]
    for r in range(N):
        for c in row_seats[r]:
            u = r + c
            v = r - c + SHIFT
            cnt[u][v] = 1
            buckets[u].append((v, r, c, aura[(r, c)]))
            seats.append((r, c, u, v, aura[(r, c)]))

    ps = [[0] * (V + 1) for _ in range(U + 1)]
    for u in range(U):
        run = 0
        for v in range(V):
            run += cnt[u][v]
            ps[u + 1][v + 1] = ps[u][v + 1] + run

    def rect_count(u0, v0, d):
        u1 = u0 + d
        v1 = v0 + d
        return ps[u1 + 1][v1 + 1] - ps[u0][v1 + 1] - ps[u1 + 1][v0] + ps[u0][v0]

    def exists(d):
        max_u0 = U - d
        max_v0 = V - d
        for u0 in range(max_u0):
            for v0 in range(max_v0):
                if rect_count(u0, v0, d) >= K:
                    return True
        return False

    lo, hi = 0, N + M - 2
    while lo < hi:
        mid = (lo + hi) // 2
        if exists(mid):
            hi = mid
        else:
            lo = mid + 1
    best_d = lo

    best_sum = None
    best_ans = None

    max_u0 = U - best_d
    max_v0 = V - best_d

    for u0 in range(max_u0):
        u1 = u0 + best_d
        for v0 in range(max_v0):
            v1 = v0 + best_d
            if rect_count(u0, v0, best_d) < K:
                continue

            inside = []
            for u in range(u0, u1 + 1):
                for v, r, c, a in buckets[u]:
                    if v0 <= v <= v1:
                        inside.append((a, r, c))

            inside.sort()
            chosen = inside[:K]
            total_aura = sum(value[0] for value in chosen)

            if best_sum is None or total_aura < best_sum:
                best_sum = total_aura
                best_ans = [(r, c) for _, r, c in chosen]

    return best_ans

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
