import sys
from math import gcd

def main():
    input = sys.stdin.read().split()
    idx = 0
    t = int(input[idx])
    idx += 1

    for tc in range(t):
        k = int(input[idx])
        n = int(input[idx + 1])
        m = int(input[idx + 2])
        p = int(input[idx + 3])
        q = int(input[idx + 4])
        idx += 5

        ax = [0] * k
        ay = [0] * k
        for i in range(k):
            ax[i] = int(input[idx])
            ay[i] = int(input[idx + 1])
            idx += 2

        x0 = ax[0]
        y0 = ay[0]

        def solve_one(a, mod, b):
            g = gcd(a, mod)
            if b % g != 0:
                return None
            a2 = a // g
            mod2 = mod // g
            b2 = (b // g) % mod2
            inv = pow(a2, -1, mod2)
            s0 = (b2 * inv) % mod2
            return (s0, mod2)

        def crt(r1, m1, r2, m2):
            g = gcd(m1, m2)
            if (r2 - r1) % g != 0:
                return None
            lcm = m1 // g * m2
            diff = (r2 - r1) // g
            m1g = m1 // g
            m2g = m2 // g
            inv = pow(m1g, -1, m2g)
            k_val = (diff * inv) % m2g
            r = (r1 + k_val * m1) % lcm
            return (r, lcm)

        best_s = None
        best_i = -1

        for i in range(k):
            dx = (ax[i] - x0) % n
            dy = (ay[i] - y0) % m
            r1 = solve_one(q, n, dx)
            if r1 is None:
                continue
            r2 = solve_one(p, m, dy)
            if r2 is None:
                continue
            c = crt(r1[0], r1[1], r2[0], r2[1])
            if c is None:
                continue
            s, period = c
            if i == 0:
                if s == 0:
                    s = period
            if best_s is None or s < best_s:
                best_s = s
                best_i = i


        #crtcrtcrtcrtcrt
        print(best_i)

main()