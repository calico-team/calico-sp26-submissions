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
    johnny_d_lecture = []

    # find all free cells
    free = []
    for i in range(N):
        for j in range(M):
            if GRID[i][j] == "-":
                free.append((i, j))

    # start BFS from first free cell
    start = free[0]
    visited = set([start])
    q = deque([start])

    while q and len(johnny_d_lecture) < K:
        r, c = q.popleft()
        johnny_d_lecture.append((r, c))

        for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M:
                if GRID[nr][nc] == "-" and (nr, nc) not in visited:
                    visited.add((nr, nc))
                    q.append((nr, nc))

    return johnny_d_lecture


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
