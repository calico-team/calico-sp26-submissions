import sys
from math import gcd
input = sys.stdin.readline

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def mod_inv(a, m):
    g, x, _ = extended_gcd(a % m, m)
    if g != 1:
        return None
    return x % m

# Solve t*coeff ≡ remainder (mod mod_val)
# Returns (t mod period, period) or None if no solution
def solve_linear_congruence(coeff, remainder, mod_val):
    g = gcd(coeff, mod_val)
    if remainder % g != 0:
        return None
    c = coeff // g
    r = remainder // g
    m = mod_val // g
    inv_c = mod_inv(c, m)
    t0 = (r * inv_c) % m
    return t0, m

# Chinese Remainder Theorem: t ≡ a1 (mod m1), t ≡ a2 (mod m2)
def crt(a1, m1, a2, m2):
    g = gcd(m1, m2)
    if (a2 - a1) % g != 0:
        return None
    lcm = m1 // g * m2
    diff = (a2 - a1) // g
    inv = mod_inv(m1 // g, m2 // g)
    t = (a1 + m1 * (diff * inv % (m2 // g))) % lcm
    return t, lcm

def min_steps_to_hit(x0, y0, xi, yi, N, M, Q, P):
    dx = (xi - x0) % N
    dy = (yi - y0) % M

    sol_x = solve_linear_congruence(Q, dx, N)
    sol_y = solve_linear_congruence(P, dy, M)

    if sol_x is None or sol_y is None:
        return None

    a1, m1 = sol_x
    a2, m2 = sol_y

    result = crt(a1, m1, a2, m2)
    if result is None:
        return None

    t, period = result
    if t == 0:
        t = period  # must be t > 0 (laser starts at asteroid 0, doesn't hit until wrap)
    return t

t_cases = int(input())
for _ in range(t_cases):
    K, N, M, P, Q = map(int, input().split())
    asteroids = []
    for i in range(K):
        x, y = map(int, input().split())
        asteroids.append((x, y))

    x0, y0 = asteroids[0]
    best_t = None
    best_idx = -1

    for i in range(K):
        xi, yi = asteroids[i]
        t = min_steps_to_hit(x0, y0, xi, yi, N, M, Q, P)
        if t is None:
            continue
        if best_t is None or t < best_t:
            best_t = t
            best_idx = i

    print(best_idx)