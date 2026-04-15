def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    # YOUR CODE HERE
    grid = [[0 for _ in range(M)] for _ in range(N)]

    # ignore corners, here they are 0

    # fill row 1
    for c in range(M):
        grid[1][c] = c % 5 # % 5 because total 5 nums (0-4)

    # fill row 0
    for c in range(M):
        down = grid[1][c]
        grid[0][c] = (down + 2) % 5

    for r in range(2,N):
        for c in range(M):
            top = grid[r-1][c]
            next = (top + 3) % 5
            grid[r][c] = next

    # print(grid)
    return grid
    # return [[0 for _ in range(M)] for _ in range(N)]


def main():
    T = int(input())
    for _ in range(T):
        temp = input().split()
        N = int(temp[0])
        M = int(temp[1])
        grid = solve(N, M)
        for row in grid:
            print(' '.join(str(x) for x in row))


if __name__ == '__main__':
    main()
