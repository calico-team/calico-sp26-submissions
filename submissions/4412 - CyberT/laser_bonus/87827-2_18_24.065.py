import sys
input = sys.stdin.readline
def g(a,b):
    if b==0:
        return a,1,0
    d,x,y = g(b,a%b)
    return d,y,x-(a//b)*y
t = int(input())
for _ in range(t):
    k,n,m,p,q = map(int,input().split())
    helper = []
    for i in range(k):
        x,y = map(int,input().split())
        helper.append((x,y))
    sx,sy = helper[0]
    best = -1
    best_i = 0
    import math
    for i in range(k):
        x,y = helper[i]
        dx = (x - sx) % n
        dy = (y - sy) % m
        g1 = math.gcd(q,n)
        if dx % g1 != 0:
            continue
        n1 = n//g1
        _,invq,_ = g(q//g1, n1)
        invq %= n1
        t1 = (dx//g1 * invq) % n1
        g2 = math.gcd(p,m)
        if dy % g2 != 0:
            continue
        m1 = m//g2
        _,invp,_ = g(p//g2, m1)
        invp %= m1
        t2 = (dy//g2 * invp) % m1
        d,x1,y1 = g(n1,m1)
        if (t2 - t1) % d != 0:
            continue
        l = n1//d * m1
        tval = (t1 + (t2 - t1)//d * x1 % (m1//d) * n1) % l
        if tval == 0:
            if i == 0:
                tval = l
            else:
                continue
        if best == -1 or tval < best:
            best = tval
            best_i = i
    print(best_i)
def read_your_input():
    pass