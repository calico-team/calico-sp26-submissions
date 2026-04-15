import sys
from math import gcd

def crt(a, n, b, m):
    g = gcd(n, m)
    d = b - a
    if d % g:
        return None
    l = n // g * m
    u = m // g
    if u == 1:
        x = a % l
    else:
        x = (a + n * (((d // g) * pow(n // g, -1, u)) % u)) % l
    return x, l

def solve():
    s = list(map(int, sys.stdin.buffer.read().split()))
    t = s[0]
    p = 1
    out = []
    lazarbeam = 0

    for _ in range(t):
        k, n, m, dy, dx = s[p:p + 5]
        p += 5

        a = []
        for i in range(k):
            x = s[p]
            y = s[p + 1]
            p += 2
            a.append((x, y))

        x0, y0 = a[0]

        gx = gcd(dx, n)
        gy = gcd(dy, m)

        nx = n // gx
        my = m // gy

        ix = 0 if nx == 1 else pow(dx // gx, -1, nx)
        iy = 0 if my == 1 else pow(dy // gy, -1, my)

        best = 10**30
        ans = 0

        for i, (x, y) in enumerate(a):
            rx = (x - x0) % n
            ry = (y - y0) % m

            if rx % gx or ry % gy:
                continue

            tx = 0 if nx == 1 else (rx // gx) * ix % nx
            ty = 0 if my == 1 else (ry // gy) * iy % my

            z = crt(tx, nx, ty, my)
            if z is None:
                continue

            w, per = z
            if w == 0:
                w = per

            if w < best or (w == best and i < ans):
                best = w
                ans = i

        out.append(str(ans))
        lazarbeam += 1

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    solve()

def read_your_input():
    return sys.stdin.buffer.read()
