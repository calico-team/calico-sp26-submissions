for _ in range(int(input())):
    N,M = map(int,input().split())
    GRID = [[0]*M for t in range(N)]
    GRID[1][1] = 2
    GRID[1][0] = 1
    GRID[1][2] = 3
    GRID[2][1] = 4
    for row in GRID:
        print(*row)