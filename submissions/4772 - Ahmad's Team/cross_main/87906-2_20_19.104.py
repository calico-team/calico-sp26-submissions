def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    grid = [[0] * M for _ in range(N)]
    for r in range(N):
        for c in range(M):
            grid[r][c] = (r + 2 * c) % 5
    return grid


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        grid = solve(N, M)
        for row in grid:
            print(' '.join(str(x) for x in row))


if __name__ == '__main__':
    main()
