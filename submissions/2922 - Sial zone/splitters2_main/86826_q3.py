T = int(input())

for _ in range(T):
    P, A, B = map(int, input().split())
    
    # Build grid large enough
    N = A + B + 5
    M = 20
    
    grid = [['.' for _ in range(M)] for _ in range(N)]
    
    r, c = 0, 0
    grid[r][c] = '>'
    
    # Handle binary (2^A)
    for i in range(A):
        grid[r][c+1] = 'v'
        grid[r+1][c+1] = '>'
        r += 1
        c += 1
    
    # Handle ternary (3^B)
    for i in range(B):
        grid[r][c] = 'S'
        grid[r][c-1] = '<'
        grid[r][c+1] = '>'
        grid[r+1][c] = 'v'
        r += 1
    
    # Bottom: decide based on P
    total = 2**A * (3**B)
    
    for j in range(M):
        if j < P:
            grid[N-1][j] = 'v'   # collected
        else:
            grid[N-1][j] = 'X'   # destroyed
    
    print(N, M)
    for row in grid:
        print(''.join(row))