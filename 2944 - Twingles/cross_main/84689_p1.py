t = int(input())

for _ in range(t):
    n,m = map(int,input().split())
    dir = [[0,0],[0,1],[1,0],[0,-1],[-1,0]]

    grid = [[-1 for i in range(m)] for j in range(n)]
    s = set([0,1,2,3,4])
    
    for i in range(1,n-1):
        for j in range(1,m-1):
            ns = set(s)
            for dx,dy in dir:
                if grid[i+dy][j+dx] != -1:
                    ns.remove(grid[i+dy][j+dx])
            for dx,dy in dir:
                if grid[i+dy][j+dx] == -1:
                    grid[i+dy][j+dx] = ns.pop()
    
    grid[0][0] = 0
    grid[0][m-1] = 0
    grid[n-1][0] = 0
    grid[n-1][m-1] = 0

    for i in grid:
        print(*i)