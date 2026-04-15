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
    seats = []
    for _ in range(total):
        seats.append([])

    for r in range(N):
        R = GRID[r]
        for c in range(M):
            if R[c] == '-':
                u = r + c
                v = r - c + M - 1
                seats[u].append(v)

    def _find(d):
        c_v = [0] * total
        r_u = -1
        w_len = d + 1

        for l_u in range(total):
            lim = l_u + d
            while r_u + 1 < total and r_u + 1 <= lim:
                r_u += 1
                for _v in seats[r_u]:
                    c_v[_v] += 1

            cur = 0
            for a in range(w_len):
                cur += c_v[a]
            if cur >= K:
                return (l_u, 0)

            max_s = total - w_len
            for s_v in range(1, max_s + 1):
                cur -= c_v[s_v - 1]
                cur += c_v[s_v + w_len - 1]
                if cur >= K:
                    return (l_u, s_v)

            for _v in seats[l_u]:
                c_v[_v] -= 1

        return None

    l, h = 0, total - 1
    best = h
    best_win = None

    while l <= h:
        d = (l + h) // 2
        win = _find(d)
        if win is not None:
            best = d
            best_win = win
            h = d - 1
        else:
            l = d + 1

    u0, v0 = best_win
    res = []

    for r in range(N):
        R = GRID[r]
        for c in range(M):
            if R[c] == '-':
                u = r + c
                v = r - c + M - 1
                if u0 <= u <= u0 + best and v0 <= v <= v0 + best:
                    res.append((r, c))
                    if len(res) == K:
                        return res

    return res


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
