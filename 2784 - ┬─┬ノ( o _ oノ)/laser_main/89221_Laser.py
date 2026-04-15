t = int(input())
for i in range(t):
    k,n,m,y,x = map(int,input().split())
    a = []
    for j in range(k):
        p = list(map(int,input().split()))
        a.append(p)
    sx,sy = a[0][0], a[0][1]
    while True:
        sx += x
        sy += y
        if sx >= n:
            sx = sx % n
        if sy >= m:
            sy = sy % m
        g = [sx,sy]
        if g in a:
            print(a.index(g))
            break
