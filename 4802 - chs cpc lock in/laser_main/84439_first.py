inf = float('inf')

def gcd(a,b):
    if a>b:
        return gcd(b,a)
    if a==0:
        return b
    return gcd(b%a, a)

for tc in range(int(input())):
    k,n,m,p,q = map(int, input().split())
    gx = gcd(q,n)
    ni = n//gx
    gy = gcd(p,m)
    mi = m//gy

    coords = [list(map(int, input().split())) for _ in range(k)]
    cx = coords[0][0]
    cy = coords[0][1]
    mem = { ((cx+i*q)%n, (cy+i*p)%m): i for i in range(1,mi*ni//gcd(mi,ni)+1)}
    t = inf
    res = -1
    for i, (xi, yi) in enumerate(coords):
        if (xi,yi) in mem:
            ti = mem[(xi,yi)]
            if ti<t:
                t = ti
                res = i
    print(res)
