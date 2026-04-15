def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    # YOUR CODE HERE
    seats = []
    U = N + M - 1
    V = N + M - 1
    shift = M - 1

    buckets = [[] for _ in range(U)]
    for r in range(N):
        row = GRID[r]
        for c in range(M):
            if row[c] == '-':
                u = r + c
                v = r - c + shift
                buckets[u].append((v, r, c))
                seats.append((u, v, r, c))

    def check(D):
        cnt = [0] * V
        left_u = 0

        for right_u in range(U):
            for v, r, c in buckets[right_u]:
                cnt[v] += 1

            while right_u - left_u > D:
                for v, r, c in buckets[left_u]:
                    cnt[v] -= 1
                left_u += 1

            curr = 0
            left_v = 0
            for right_v in range(V):
                curr += cnt[right_v]
                while right_v - left_v > D:
                    curr -= cnt[left_v]
                    left_v += 1
                if curr >= K:
                    return (left_u, right_u, left_v, right_v)

        return None

    lo, hi = 0, N + M
    best = None

    while lo <= hi:
        mid = (lo + hi) // 2
        got = check(mid)
        if got is not None:
            best = got
            hi = mid - 1
        else:
            lo = mid + 1

    u1, u2, v1, v2 = best
    ans = []
    for u, v, r, c in seats:
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
