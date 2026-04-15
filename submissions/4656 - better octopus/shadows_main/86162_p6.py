for _ in range(int(input())):
    n=int(input())
    a=[input().count('#') for i in range(n)]
    b=[input().count('#') for i in range(n)]
    x,y=0,0
    for i in range(n):
        x+=a[i]*b[i]
        y+=max(a[i],b[i])
    print(x,y)
