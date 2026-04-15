import bisect
from collections import defaultdict


def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    # YOUR CODE HERE

    aura_grid = {}
    cells = []
    for i in range(N):
        row = GRID[i]

        left_occ = 0
        for j in range(M):
            if row[j] == "-":
                right_occ = sum(1 for jj in range(j + 1, M) if row[jj] == "#")
                aura_grid[(i, j)] = min(left_occ, right_occ)
                cells.append((i, j))
            elif row[j] == "#":
                left_occ += 1

    S = len(cells)
    if K == 1:
        best = min(cells, key=lambda p: aura_grid[p])
        return [best]

    by_u = sorted(cells, key=lambda p: p[0] + p[1])
    us = [p[0] + p[1] for p in by_u]
    vs = [p[0] - p[1] for p in by_u]

    def check_fast(D):
        v_sorted = []
        left = 0
        for right in range(S):
            bisect.insort(v_sorted, vs[right])
            while us[right] - us[left] > D:
                v_sorted.pop(bisect.bisect_left(v_sorted, vs[left]))
                left += 1
            sz = len(v_sorted)
            if sz >= K:

                if v_sorted[-1] - v_sorted[0] <= D:
                    return True

                for i in range(sz - K + 1):

                    count = bisect.bisect_right(v_sorted, v_sorted[i] + D) - i
                    if count >= K:
                        return True
        return False

    lo, hi = 0, (N - 1) + (M - 1)
    while lo < hi:
        mid = (lo + hi) // 2
        if check_fast(mid):
            hi = mid
        else:
            lo = mid + 1

    best_D = lo

    best_seats = None
    best_aura = float("inf")

    window = []
    left = 0

    for right in range(S):
        r, c = by_u[right]
        v_val = r - c
        bisect.insort(window, (v_val, r, c))

        while us[right] - us[left] > best_D:
            rl, cl = by_u[left]
            window.pop(bisect.bisect_left(window, (rl - cl, rl, cl)))
            left += 1

        sz = len(window)
        if sz >= K:
            for i in range(sz - K + 1):
                if window[i + K - 1][0] - window[i][0] <= best_D:
                    total_aura = sum(
                        aura_grid[(window[i + j][1], window[i + j][2])]
                        for j in range(K)
                    )
                    if total_aura < best_aura:
                        best_aura = total_aura
                        best_seats = [
                            (window[i + j][1], window[i + j][2]) for j in range(K)
                        ]

        if best_aura == 0:
            break

    return best_seats


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


if __name__ == "__main__":
    main()
