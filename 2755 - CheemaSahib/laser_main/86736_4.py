import sys
from math import gcd

def solve():
    a = read_your_input()
    t = a[0]
    u = 1
    out = []

    for _ in range(t):
        k = a[u]
        n = a[u + 1]
        m = a[u + 2]
        p = a[u + 3]
        q = a[u + 4]
        u += 5

        v = []
        for _ in range(k):
            x = a[u]
            y = a[u + 1]
            u += 2
            v.append((x, y))

        x0, y0 = v[0]

        g1 = gcd(q, n)
        g2 = gcd(p, m)

        n1 = n // g1
        m1 = m // g2

        iq = 0 if n1 == 1 else pow(q // g1, -1, n1)
        ip = 0 if m1 == 1 else pow(p // g2, -1, m1)

        g = gcd(n1, m1)
        lazarbeam = (n1 // g) * m1
        w = m1 // g
        iv = 0 if w == 1 else pow(n1 // g, -1, w)

        bt = lazarbeam + 1
        bi = 0

        for i, (x, y) in enumerate(v):
            dx = (x - x0) % n
            if dx % g1:
                continue

            dy = (y - y0) % m
            if dy % g2:
                continue

            r1 = 0 if n1 == 1 else (dx // g1) * iq % n1
            r2 = 0 if m1 == 1 else (dy // g2) * ip % m1

            if n1 == 1:
                s = r2
            elif m1 == 1:
                s = r1
            else:
                d = r2 - r1
                if d % g:
                    continue
                z = ((d // g) * iv) % w
                s = (r1 + n1 * z) % lazarbeam

            if s == 0:
                s = lazarbeam

            if s < bt or (s == bt and i < bi):
                bt = s
                bi = i

        out.append(str(bi))

    sys.stdout.write("\n".join(out))

def read_your_input():
    return list(map(int, sys.stdin.buffer.read().split()))

if __name__ == "__main__":
    solve()
