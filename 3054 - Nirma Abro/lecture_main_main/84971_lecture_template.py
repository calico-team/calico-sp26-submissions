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

    # collect all free seats
    for i in range(N):
        for j in range(M):
            if GRID[i][j] == "-":
                johnny_d_lecture.append((i, j))

    # greedy pick (sorted order ensures compact cluster)
    johnny_d_lecture.sort()

    return johnny_d_lecture[:K]


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
