a=int(input())
for i in range(a):
    n,m=map(int,input().split())
    for j in range(n):
        row=[]
        for k in range(m):
            row.append(str((j+2*k)%5))
        print(" ".join(row))
    if i !=a-1:
        print()