def solve(N, M, K, GRID):
    S = N + M - 1
    offset = M - 1

    p = []
    pref = [[0] * (S + 1) for _ in range(S + 1)]

    for r in range(N):
        rows = GRID[r]
        for c in range(M):
            if rows[c] == '-':
                u = r + c
                v = r - c + offset
                p.append((r, c, u, v))
                pref[u + 1][v + 1] += 1

    for i in range(1, S + 1):
        rows = pref[i]
        prev = pref[i - 1]
        run = 0
        for j in range(1, S + 1):
            run += rows[j]
            rows[j] = prev[j] + run

    def rect_count(u1, v1, u2, v2):
        return (
            pref[u2 + 1][v2 + 1]
            - pref[u1][v2 + 1]
            - pref[u2 + 1][v1]
            + pref[u1][v1]
        )

    def window_finder(D):
        limit = S - D
        for u1 in range(limit):
            u2 = u1 + D
            for v1 in range(limit):
                v2 = v1 + D
                if rect_count(u1, v1, u2, v2) >= K:
                    return (u1, v1)
        return None

    lo, hi = 0, S - 1
    while lo < hi:
        mid = (lo + hi) // 2
        if window_finder(mid) is not None:
            hi = mid
        else:
            lo = mid + 1

    D = lo
    u1, v1 = window_finder(D)
    u2, v2 = u1 + D, v1 + D

    ans = []
    for r, c, u, v in p:
        if u1 <= u <= u2 and v1 <= v <= v2:
            ans.append((r, c))
            if len(ans) == K:
                break
    return ans

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
