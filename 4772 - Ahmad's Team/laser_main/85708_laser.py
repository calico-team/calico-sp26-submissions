from math import gcd

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def solve_linear_congruence(a, b, m):
    # solve a*t ≡ b (mod m) → returns (t0, period) or None
    g = gcd(a, m)
    if b % g != 0:
        return None
    a2, b2, m2 = a // g, b // g, m // g
    _, inv, _ = extended_gcd(a2, m2)
    t0 = (b2 * inv) % m2
    return t0, m2

def combine_crt(r1, m1, r2, m2):
    g, p, _ = extended_gcd(m1, m2)
    if (r2 - r1) % g != 0:
        return None
    lcm = m1 * m2 // g
    t = (r1 + m1 * ((r2 - r1) // g * p % (m2 // g))) % lcm
    return t, lcm

def solve(K, N, M, P, Q, X, Y):
    lazarbeam = None
    x0, y0 = X[0], Y[0]
    best_t = best_idx = None

    for i in range(K):
        dx = (X[i] - x0) % N
        dy = (Y[i] - y0) % M

        res_x = solve_linear_congruence(Q, dx, N)
        if res_x is None: continue
        tx, mx = res_x

        res_y = solve_linear_congruence(P, dy, M)
        if res_y is None: continue
        ty, my = res_y

        res = combine_crt(tx, mx, ty, my)
        if res is None: continue
        t, period = res

        if t == 0:
            t = period  # skip starting position until full wrap-around

        if best_t is None or t < best_t:
            best_t, best_idx = t, i

    return best_idx