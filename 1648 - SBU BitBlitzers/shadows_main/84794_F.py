t = int(input())
for _ in range(t):
    n = int(input())
    grid1 = []
    for _ in range(n):
        grid1.append(input())
    grid2 = []
    for _ in range(n):
        grid2.append(input())
    
    minans = 0
    maxans = n*n*n
    for i in range(n):
        c1 = 0
        c2 = 0
        for j in range(n):
            if grid1[i][j]=='#':
                c1+=1 
            if grid2[i][j]=='#':
                c2+=1 
        minans+=max(c1,c2)
    for i in range(n):
        c1 = 0
        c2 = 0
        for j in range(n):
            if grid1[i][j]=='.':
                c1+=1 
                maxans-=n 
        for j in range(n):
            if grid2[i][j]=='.':
                maxans-=(n-c1)
    print(f'{maxans} {minans}')
    