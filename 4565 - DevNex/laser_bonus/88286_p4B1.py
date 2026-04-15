from math import gcd

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def modinv(a, m):
    g, x, _ = extended_gcd(a, m)
    if g != 1:
        return None
    return x % m

def solve_linear_congruence(a, b, m):
    g = gcd(a, m)
    if b % g != 0:
        return None
    a2, b2, m2 = a // g, b // g, m // g
    t0 = (b2 * modinv(a2, m2)) % m2
    return t0, m2

def crt(r1, m1, r2, m2):
    g = gcd(m1, m2)
    if (r2 - r1) % g != 0:
        return None
    lcm = m1 // g * m2
    m2g = m2 // g
    diff = ((r2 - r1) // g) % m2g
    k = (diff * modinv(m1 // g, m2g)) % m2g
    return (r1 + m1 * k) % lcm, lcm

def solve(K, N, M, P, Q, asteroids):
    x0, y0 = asteroids[0]
    lazarbeam = float('inf')
    best_idx = -1

    for i in range(K):
        xi, yi = asteroids[i]
        dx = (xi - x0) % N
        dy = (yi - y0) % M

        res1 = solve_linear_congruence(Q, dx, N)
        if res1 is None:
            continue
        t1, mod1 = res1

        res2 = solve_linear_congruence(P, dy, M)
        if res2 is None:
            continue
        t2, mod2 = res2

        res = crt(t1, mod1, t2, mod2)
        if res is None:
            continue
        t, mod = res

        if t == 0 and i == 0:
            t = mod

        if t < lazarbeam:
            lazarbeam = t
            best_idx = i

    return best_idx

def read_your_input():
    T = int(input())
    for _ in range(T):
        K, N, M, P, Q = map(int, input().split())
        asteroids = []
        for _ in range(K):
            x, y = map(int, input().split())
            asteroids.append((x, y))
        print(solve(K, N, M, P, Q, asteroids))

read_your_input()