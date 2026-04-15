from math import gcd

def exgcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = exgcd(b, a % b)
    return g, y, x - (a // b) * y

t = int(input())
for _ in range(t):
    k, n, m, p, q = map(int, input().split())
    pts = []
    for i in range(k):
        a, b = map(int, input().split())
        pts.append((a, b))
    sx = pts[0][0]
    sy = pts[0][1]
    best = -1
    bs = float('inf')
    for i in range(k):
        dx = (pts[i][0] - sx) % n
        dy = (pts[i][1] - sy) % m

        # solve q*s = dx mod n
        g1 = gcd(q, n)
        if dx % g1 != 0:
            continue
        nn = n // g1
        _, xx, _ = exgcd((q // g1) % nn, nn)
        r1 = (dx // g1 * xx) % nn
        m1 = nn

        # solve p*s = dy mod m
        g2 = gcd(p, m)
        if dy % g2 != 0:
            continue
        mm = m // g2
        _, yy, _ = exgcd((p // g2) % mm, mm)
        r2 = (dy // g2 * yy) % mm
        m2 = mm

        # crt
        g3 = gcd(m1, m2)
        if (r2 - r1) % g3 != 0:
            continue
        lcm = m1 // g3 * m2
        d = (r2 - r1) // g3
        mg = m2 // g3
        _, zz, _ = exgcd((m1 // g3) % mg, mg)
        j = (d * zz) % mg
        s = (r1 + m1 * j) % lcm
        if s == 0:
            s = lcm

        if s < bs:
            bs = s
            best = i
    print(best)
