def solve(N, M, K, GRID):
    INF = 10**18

    seats = []
    for r in range(N):
        for c in range(M):
            if GRID[r][c] == "-":
                seats.append((r, c))

    if K == 0:
        return []
    if K == 1:
        return [seats[0]]

    def best_window(sorted_seats):
        best = None
        best_cost = INF
        for i in range(len(sorted_seats) - K + 1):
            group = sorted_seats[i : i + K]
            rows = [p[0] for p in group]
            cols = [p[1] for p in group]
            r_lo, r_hi = min(rows), max(rows)
            c_lo, c_hi = min(cols), max(cols)
            cost = (r_hi - r_lo) + (c_hi - c_lo)
            if cost < best_cost:
                best_cost = cost
                best = group
        return best

    def key_sum(p):
        return p[0] + p[1]

    def key_row_minus_col(p):
        return p[0] - p[1]

    def key_minus_row_plus_col(p):
        return -p[0] + p[1]

    def key_neg_sum(p):
        return -p[0] - p[1]

    ways_to_sort = [key_sum, key_row_minus_col, key_minus_row_plus_col, key_neg_sum]

    ans = None
    ans_cost = INF

    for key_fn in ways_to_sort:
        ordered = sorted(seats, key=key_fn)
        candidate = best_window(ordered)
        rows = [p[0] for p in candidate]
        cols = [p[1] for p in candidate]
        cost = (max(rows) - min(rows)) + (max(cols) - min(cols))
        if cost < ans_cost:
            ans_cost = cost
            ans = candidate

    return ans


def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        GRID = [input().strip() for _ in range(N)]
        res = solve(N, M, K, GRID)
        for r, c in res:
            print(r, c)


if __name__ == "__main__":
    main()
