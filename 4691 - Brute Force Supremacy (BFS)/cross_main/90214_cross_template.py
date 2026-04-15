def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    N: number of rows in the grid
    M: number of columns in the grid
    """
    ans = [[-1 for _ in range(M)] for _ in range(N)]
    ans[0][0] = 0
    
    for i in range(N):
        for j in range(M):
            if j==0:
                if i>0:
                    ans[i][j] = (ans[i-1][j]-1)%5
                continue
            ans[i][j] = (ans[i][j-1]+2)%5

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
