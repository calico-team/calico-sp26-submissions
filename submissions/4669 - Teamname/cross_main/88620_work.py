# ﷽
def rotate90(a):
    n, m = len(a), len(a[0])
    b = [[0]*n for _ in range(m)]
    for i in range(n):
        for j in range(m):
            b[j][n-1-i] = a[i][j]
    return b
for _ in range(int(input())):
    n,m=list(map(int,input().split()))
    t=0
    if(n>3):
       t=1
    n,m=min(n,m),max(n,m)
    grid=[]
    if(n>=1):    
      grid.append([0 for i in range(m)])
    if(n>=2):    
      grid.append([1+(i)%3 for i in range(m)])
    if(n==3):
        grid.append([4 for i in range(m)])
    if t:
        grid=rotate90(grid)
    for i in grid:
        print(*i)