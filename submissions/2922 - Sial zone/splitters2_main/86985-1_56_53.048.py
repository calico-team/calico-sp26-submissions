T = int(input())

for _ in range(T):
    P, A, B = map(int, input().split())
    
    D = A + B
    
    # compute good paths
    good = P * (3 ** A)
    
    N = D + 3
    M = 2 * D + 3
    
    grid = [['.' for _ in range(M)] for _ in range(N)]
    
    c = M // 2
    
    # build splitter chain
    for i in range(D):
        grid[i][c] = 'S'
        grid[i][c-1] = '<'
        grid[i][c+1] = '>'
        grid[i+1][c] = 'v'
    
    # bottom row routing
    count = 0
    for j in range(M):
        if count < good:
            grid[N-1][j] = 'v'   # collected
            count += 1
        else:
            grid[N-1][j] = 'X'
    
    # entry
    grid[0][0] = '>'
    
    print(N, M)
    for row in grid:
        print(''.join(row))