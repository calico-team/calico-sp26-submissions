from collections import deque


def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    # YOUR CODE HERE

    cells = []
    for i in range(N):
        for j in range(M):
            if GRID[i][j] == "-":
                cells.append((i, j))

    if K == 1:
        return [cells[0]]

    cells_u = sorted(cells, key=lambda p: p[0] + p[1])

    def check(D):
        vs = deque()  # <-- only change from before
        left = 0
        for right in range(len(cells_u)):
            r, c = cells_u[right]
            vs.append(r - c)
            while (cells_u[right][0] + cells_u[right][1]) - (
                cells_u[left][0] + cells_u[left][1]
            ) > D:
                vs.popleft()  # <-- O(1) instead of O(n)
                left += 1
            if len(vs) >= K:
                sv = sorted(vs)
                for i in range(len(sv) - K + 1):
                    if sv[i + K - 1] - sv[i] <= D:
                        return True
        return False

    lo, hi = 0, (N - 1) + (M - 1)
    while lo < hi:
        mid = (lo + hi) // 2
        if check(mid):
            hi = mid
        else:
            lo = mid + 1

    best_D = lo

    def aura(r, c):
        left_occ = sum(1 for j in range(c) if GRID[r][j] == "#")
        right_occ = sum(1 for j in range(c + 1, M) if GRID[r][j] == "#")
        return min(left_occ, right_occ)

    best_seats = None
    best_aura = float("inf")
    vs_window = deque()  # <-- same fix here
    left = 0

    for right in range(len(cells_u)):
        r, c = cells_u[right]
        vs_window.append((r - c, r, c))
        while (cells_u[right][0] + cells_u[right][1]) - (
            cells_u[left][0] + cells_u[left][1]
        ) > best_D:
            vs_window.popleft()  # <-- O(1)
            left += 1
        if len(vs_window) >= K:
            sv = sorted(vs_window, key=lambda x: x[0])
            for i in range(len(sv) - K + 1):
                if sv[i + K - 1][0] - sv[i][0] <= best_D:
                    candidate = sv[i : i + K]
                    total_aura = sum(aura(x[1], x[2]) for x in candidate)
                    if best_seats is None or total_aura < best_aura:
                        best_aura = total_aura
                        best_seats = [(x[1], x[2]) for x in candidate]

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
