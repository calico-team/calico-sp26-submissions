def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    grid = [[0 for _ in range(M)] for _ in range(N)]
    
    for i in range(N):
        for j in range(M):
            grid[i][j] = (i + j) % 5

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