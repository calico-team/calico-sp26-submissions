T = int(input())

for _ in range(T):
    P, A, B = map(int, input().split())
    
    N = B + 2
    M = 2 * B + 5
    
    grid = [['.' for _ in range(M)] for _ in range(N)]
    
    col = M // 2
    
    for i in range(B):
        grid[i][col] = 'S'
        grid[i][col - 1] = '<'
        grid[i][col + 1] = '>'
        grid[i + 1][col] = 'v'

    for j in range(M):
        if j % 2 == 0:
            grid[N - 1][j] = 'X'
        else:
            grid[N - 1][j] = 'v'
    
    grid[0][0] = '>'
    
    print(N, M)
    for row in grid:
        print(''.join(row))