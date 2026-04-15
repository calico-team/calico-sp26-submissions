def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    # YOUR CODE HERE
    grid = [[0 for _ in range(M)] for _ in range(N)]
    for i in range(N):
        for j in range(M):
            if i == 0 and j == 1:
                grid[i][j] = 0
            elif i == 1 and j == 0:
                grid[i][j] = 1
            elif i == 1 and j == 1:
                grid[i][j] = 2
            elif i == 1 and j == 2:
                grid[i][j] = 3
            elif i == 2 and j == 1:
                grid[i][j] = 4
            else:
                grid[i][j] = 0
    return grid


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
