inf = float('inf')

def gcd(a,b):
    if a>b:
        return gcd(b,a)
    if a==0:
        return b
    return gcd(b%a, a)

def inv(a, b):
    ia, ib = a, b
    v00 = 0
    v01 = 1
    v10 = 1
    v11 = 0
    while a:
        q = b//a
        v00, v01 = v01, v00+v01*q
        v10, v11 = v11, v10+v11*q
        a,b = b%a, a
    if (ia*v00 + 1)%ib == 0:
        v00 = ib-v00
    return v00

for tc in range(int(input())):
    k,n,m,p,q = map(int, input().split())

    gx = gcd(q,n)
    n0 = n//gx
    q0 = q//gx
    qinv = inv(q0, n0)

    gy = gcd(p,m)
    m0 = m//gy
    p0 = p//gy
    pinv = inv(p0, m0)

    mini = gcd(m0, n0)
    n1 = n0//mini
    m1 = m0//mini
    n1inv = inv(n1%m1, m1)
    m1inv = inv(m1%n1, n1)

    coords = [list(map(int, input().split())) for _ in range(k)]
    cx = coords[0][0]
    cy = coords[0][1]
    t = inf
    res = -1
    for i, (xi, yi) in enumerate(coords):
        xi -= cx
        yi -= cy
        if xi%gx or yi%gy:
            continue
        xi //= gx
        xi = (xi*qinv)%n0
        yi //= gy
        yi = (yi*pinv)%m0
        if xi%mini != yi%mini:
            continue
        r = xi%mini
        xi = (xi-r)//mini
        xi %= n1
        yi = (yi-r)//mini
        yi %= m1
        ti = r
        plus = xi * m1 * m1inv + yi * n1 * n1inv
        plus %= m1 * n1
        ti += mini * plus
        if t==0:
            t = m1 * n1 * mini
        if ti<t:
            t = ti
            res = i
    print(res)
