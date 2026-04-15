# ﷽
for _ in range(int(input())):
    n=int(input())
    mi=0
    ma=n*n*n 
    grid1=[list(input()) for i in range(n)]
    grid2=[list(input()) for i in range(n)]
    used=[0 for i in range(n)]
    used2=[0 for i in range(n)]
    z=0
    for row in range(n):
        for column in range(n):
            if(grid1[row][column]=='.'):
                used[row]+=1 
                ma-=n
    for row in range(n):
        for column in range(n):
            if(grid2[row][column]=='.'):
                ma-=n                
                ma+=used[row]
            else:
               used2[row]+=1 
    for i in range(n):
        mi+=max(n-used[i],used2[i])
    print(ma,mi-z)            