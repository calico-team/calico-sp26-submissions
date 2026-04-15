import math

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def modinv(a, m):
    g, x, _ = extended_gcd(a % m, m)
    return x % m if g == 1 else None

def solve_linear_mod(a, b, m):
    g = math.gcd(a, m)
    if b % g != 0:
        return None, None
    a2, b2, m2 = a // g, b // g, m // g
    t = (b2 * modinv(a2, m2)) % m2
    return t, m2

def solve_crt(r1, m1, r2, m2):
    g, u, _ = extended_gcd(m1, m2)
    if (r2 - r1) % g != 0:
        return None
    lcm = m1 // g * m2
    t = (r1 + m1 * ((r2 - r1) // g * u % (m2 // g))) % lcm
    return t

def solve():
    k, n, m, p, q = map(int, input().split())
    asteroids = [tuple(map(int, input().split())) for _ in range(k)]
    x0, y0 = asteroids[0]
    lazarbeam = None
    best_t = None

    for i, (xi, yi) in enumerate(asteroids):
        dx, dy = (xi - x0) % n, (yi - y0) % m
        tx, period_x = solve_linear_mod(q, dx, n)
        ty, period_y = solve_linear_mod(p, dy, m)
        if tx is None or ty is None:
            continue
        t = solve_crt(tx, period_x, ty, period_y)
        if t is None:
            continue
        period = period_x // math.gcd(period_x, period_y) * period_y
        if t == 0:
            t = period
        if best_t is None or t < best_t:
            best_t, lazarbeam = t, i
    print(lazarbeam)

t = int(input())
for _ in range(t):
    solve()
