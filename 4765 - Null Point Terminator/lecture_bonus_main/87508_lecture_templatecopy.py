def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    # YOUR CODE HERE
    total = N + M - 1
    seats = [[] for _ in range(total)]

    aura = [[-1] * M for _ in range(N)]
    for r in range(N):
        row = GRID[r]
        occ = row.count('#')
        left = 0
        for c in range(M):
            if row[c] == '#':
                left += 1
            else:
                aura[r][c] = left if left < occ - left else occ - left

    for r in range(N):
        row = GRID[r]
        base = M - 1 + r
        for c in range(M):
            if row[c] == '-':
                u = r + c
                v = base - c
                seats[u].append(v)

    def find_any(d):
        cnt_v = [0] * total
        r_u = -1
        w = d + 1
        max_sv = total - w

        for l_u in range(total):
            lim = l_u + d
            if lim >= total:
                lim = total - 1

            while r_u < lim:
                r_u += 1
                for v in seats[r_u]:
                    cnt_v[v] += 1

            cur = 0
            for i in range(w):
                cur += cnt_v[i]
            if cur >= K:
                return l_u, 0

            for sv in range(1, max_sv + 1):
                cur += cnt_v[sv + w - 1] - cnt_v[sv - 1]
                if cur >= K:
                    return l_u, sv

            for v in seats[l_u]:
                cnt_v[v] -= 1

        return None

    low, high = 0, total - 1
    best = total - 1
    best_win = (0, 0)

    while low <= high:
        mid = (low + high) >> 1
        win = find_any(mid)
        if win is not None:
            best = mid
            best_win = win
            high = mid - 1
        else:
            low = mid + 1

    u0, v0 = best_win
    cand = []
    shift = M - 1

    for r in range(N):
        row = GRID[r]
        base = shift + r
        for c in range(M):
            if row[c] == '-':
                u = r + c
                v = base - c
                if u0 <= u <= u0 + best and v0 <= v <= v0 + best:
                    cand.append((aura[r][c], r, c))

    cand.sort()
    return [(cand[i][1], cand[i][2]) for i in range(K)]



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
