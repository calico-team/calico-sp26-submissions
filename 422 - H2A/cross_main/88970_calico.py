for _ in range(int(input())):
    m,n=list(map(int,input().split()))
    for i in range(m):
        for j in range(n):
            print((i+2*j)%5,end=' ')
        print()
