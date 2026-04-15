import sys
import math

def solve_linear(a, b, m):
    g = math.gcd(a, m)
    if b % g != 0: 
        return -1, -1
    m_prime = m // g
    if m_prime == 1:
        return 0, 1
    inv = pow(a // g, -1, m_prime)
    res = ((b // g) * inv) % m_prime
    return res, m_prime

def crt(r1, m1, r2, m2):
    g = math.gcd(m1, m2)
    if (r1 - r2) % g != 0:
        return -1, -1
    m2_g = m2 // g
    if m2_g == 1:
        return r1 % m1, m1
    inv = pow(m1 // g, -1, m2_g)
    k = (((r2 - r1) // g) * inv) % m2_g
    lcm = m1 * m2_g
    ans = (r1 + m1 * k) % lcm
    return ans, lcm

def solve():
    data = sys.stdin.read().split()
    if not data: return
    t = int(data[0])
    idx = 1
    for _ in range(t):
        k = int(data[idx])
        n = int(data[idx+1])
        m = int(data[idx+2])
        p = int(data[idx+3])
        q = int(data[idx+4])
        idx += 5
        x0, y0 = int(data[idx]), int(data[idx+1])
        asteroids = []
        for i in range(k):
            asteroids.append((int(data[idx]), int(data[idx+1])))
            idx += 2
        ans_idx = -1
        min_s = float('inf')
        for i in range(k):
            xi, yi = asteroids[i]
            dx = (xi - x0) % n
            dy = (yi - y0) % m
            r1, m1 = solve_linear(q, dx, n)
            if m1 == -1: continue
            r2, m2 = solve_linear(p, dy, m)
            if m2 == -1: continue
            s, lcm = crt(r1, m1, r2, m2)
            if lcm == -1: continue
            if s == 0:
                s = lcm
            if s < min_s:
                min_s = s
                ans_idx = i
        print(ans_idx)

if __name__ == '__main__':
    solve()