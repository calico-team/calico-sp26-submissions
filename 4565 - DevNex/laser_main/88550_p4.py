import sys
from math import gcd

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def solve_linear_congruence(a, b, m):
    g = gcd(a, m)
    if b % g != 0:
        return None
    a_, b_, m_ = a // g, b // g, m // g
    _, inv, _ = extended_gcd(a_, m_)
    t0 = (b_ * inv) % m_
    return (t0, m_)

def combine_crt(r1, m1, r2, m2):
    g = gcd(m1, m2)
    if (r2 - r1) % g != 0:
        return None
    lcm = m1 * m2 // g
    _, inv, _ = extended_gcd(m1 // g, m2 // g)
    t = (r1 + m1 * ((r2 - r1) // g * inv % (m2 // g))) % lcm
    return (t, lcm)

def lazarbeam(K, N, M, P, Q, asteroids):
    x0, y0 = asteroids[0]
    asteroid_set = {}
    for i in range(K):
        key = (asteroids[i][0], asteroids[i][1])
        if key not in asteroid_set:
            asteroid_set[key] = i

    best_t = None
    best_idx = None

    for i in range(K):
        xi, yi = asteroids[i]
        dx = (xi - x0) % N
        dy = (yi - y0) % M

        sol_x = solve_linear_congruence(Q, dx, N)
        sol_y = solve_linear_congruence(P, dy, M)

        if sol_x is None or sol_y is None:
            continue

        r1, m1 = sol_x
        r2, m2 = sol_y

        res = combine_crt(r1, m1, r2, m2)
        if res is None:
            continue

        t, mod = res
        if t == 0:
            t = mod 

        if best_t is None or t < best_t:
            best_t = t
            best_idx = i

    return best_idx

def read_your_input():
    input_data = sys.stdin.read().split()
    idx = 0
    T = int(input_data[idx]); idx += 1
    results = []
    for _ in range(T):
        K, N, M, P, Q = int(input_data[idx]), int(input_data[idx+1]), int(input_data[idx+2]), int(input_data[idx+3]), int(input_data[idx+4])
        idx += 5
        asteroids = []
        for i in range(K):
            x, y = int(input_data[idx]), int(input_data[idx+1])
            idx += 2
            asteroids.append((x, y))
        results.append(lazarbeam(K, N, M, P, Q, asteroids))
    for r in results:
        print(r)

read_your_input()