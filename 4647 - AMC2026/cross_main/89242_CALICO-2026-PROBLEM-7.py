def cross(N, M):
    grid = [[0] * M for _ in range(N)]
    
    for i in range(1, N-1):
        for j in range(1, M-1):
            offset = (i * M + j) % 5
            grid[i-1][j] = (0 + offset) % 5
            grid[i][j-1] = (1 + offset) % 5
            grid[i][j] = (2 + offset) % 5
            grid[i][j+1] = (3 + offset) % 5
            grid[i+1][j] = (4 + offset) % 5
    
    return grid

def inputs():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        grid = cross(N, M)
        for row in grid:
            print(' '.join(map(str, row)))
inputs()
