# Source: https://usaco.guide/general/io
t= int(input())
for _ in range(t):
    n,p,r,k = map(int,input().split())
    E = list(map(int,input().split()))
    lose = False
    for i in range(n):
        p-=E[i]
        if p<0:
            lose = True 
            break 
        if  (i+1)%k == 0:
            p+= r
    if lose:
        print("nah i'd lose")
    else:
        print("nah i'd win")
