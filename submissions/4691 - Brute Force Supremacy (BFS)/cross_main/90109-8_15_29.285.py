def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    ans = [[-1 for _ in range(M)] for _ in range(N)]
    neighbors = [(-1, 0), (0, 1), (0, -1), (1, 0)]
    ans[1][1] = 0
    ans[0][0] = 0
    ans[0][M-1] = 0
    ans[N-1][0] = 0
    ans[N-1][M-1] = 0
    n = [[1,2,3,4],[2,3,4,0],[3,4,0,1],[4,0,1,2],[0,1,2,3]]
    
    for i in range(1,N-1):
        for j in range(1,M-1):
            for k in range(4):
                dx,dy = neighbors[k]
                ans[i+dx][j+dy]=n[ans[i][j]][k]
        if (i,j)==(1,1):
            return ans

    return ans


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
