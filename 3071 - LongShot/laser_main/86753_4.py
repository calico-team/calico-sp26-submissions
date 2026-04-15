import sys
import math


def m9(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = m9(b, a % b)
    return g, y1, x1 - (a // b) * y1
def m8(a, m):
    g, x, _ = m9(a, m)
    if g != 1:
        return None
    return x % m
def m6(r1, m1, r2, m2):
    g, s, _ = m9(m1, m2)
    if (r2 - r1) % g != 0:
        return None, None
    lcm = m1 // g * m2
    k = ((r2 - r1) // g * s) % (m2 // g)
    r = (r1 + m1 * k) % lcm
    return r, lcm
if __name__ == "__main__":
    data = sys.stdin.buffer.read().split()
    it = iter(data)
    T = int(next(it))
    out_lines = []
    for _ in range(T):
        K = int(next(it))
        N = int(next(it))
        M = int(next(it))
        P = int(next(it))
        Q = int(next(it))
        asteroids = []
        for __ in range(K):
            x = int(next(it))
            y = int(next(it))
            asteroids.append((x, y))

        x0, y0 = asteroids[0]
        if K == 1:
            out_lines.append("-1")
            continue
        INF = 10**30
        best_step = INF
        best = -1
        for i in range(1, K):
            X, Y = asteroids[i]
            dx = (X - x0) % N
            dy = (Y - y0) % M
            g1 = math.gcd(Q, N)
            if dx % g1 != 0:
                continue
            n1 = N // g1
            q1 = Q // g1
            dx1 = dx // g1
            inv_q = m8(q1, n1)
            if inv_q is None:
                continue
            t1 = (inv_q * dx1) % n1

            g2 = math.gcd(P, M)
            if dy % g2 != 0:
                continue
            m1 = M // g2
            p1 = P // g2
            dy1 = dy // g2
            inv_p = m8(p1, m1)
            if inv_p is None:
                continue
            t2 = (inv_p * dy1) % m1
            r, mod = m6(t1, n1, t2, m1)
            if r is None:
                continue
            if r == 0:
                r = mod
            if r < best_step:
                best_step = r
                best = i
        if best == -1:
            if K > 1:
                out_lines.append("0")  
            else:
                out_lines.append("-1")
        else :
            out_lines.append(str(best))
    sys.stdout.write("\n".join(out_lines))