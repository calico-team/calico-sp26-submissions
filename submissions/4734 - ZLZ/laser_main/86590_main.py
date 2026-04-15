import sys
input = sys.stdin.readline

def exgcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = exgcd(b, a % b)
    return g, y1, x1 - (a // b) * y1

def inv(a, mod):
    g, x, _ = exgcd(a, mod)
    if g != 1:
        return None
    return x % mod

def crt(r1, m1, r2, m2):
    g, x, y = exgcd(m1, m2)
    if (r2 - r1) % g != 0:
        return None, None
    lcm = m1 // g * m2
    t = ((r2 - r1) // g * x % (m2 // g)) * m1 + r1
    return t % lcm, lcm

def solve():
    T = int(input())
    for _ in range(T):
        K, N, M, P, Q = map(int, input().split())
        pts = [tuple(map(int, input().split())) for _ in range(K)]
        x0, y0 = pts[0]

        best_t = None
        best_i = 0

        for i, (xi, yi) in enumerate(pts):
            dx = (xi - x0) % N
            dy = (yi - y0) % M

            g1 = __import__("math").gcd(Q, N)
            if dx % g1 != 0:
                continue
            n1 = N // g1
            t1 = (dx // g1) * inv(Q // g1, n1) % n1

            g2 = __import__("math").gcd(P, M)
            if dy % g2 != 0:
                continue
            n2 = M // g2
            t2 = (dy // g2) * inv(P // g2, n2) % n2

            t, mod = crt(t1, n1, t2, n2)
            if t is None:
                continue

            if t == 0:
                t = mod

            if best_t is None or t < best_t:
                best_t = t
                best_i = i

        print(best_i)

def read_your_input():
    solve()

if __name__ == "__main__":
    read_your_input()