import sys
from math import gcd

def extended_gcd(a, b):
    if a == 0:
        return b, 0, 1
    g, x, y = extended_gcd(b % a, a)
    return g, y - (b // a) * x, x

def modinv(a, m):
    g, x, _ = extended_gcd(a % m, m)
    if g != 1:
        return None
    return x % m

def solve_linear_congruence(a, b, m):
    """Solve a*t ≡ b (mod m). Returns (residue, period) or None."""
    g = gcd(a, m)
    if b % g != 0:
        return None
    a2, b2, m2 = a // g, b // g, m // g
    inv = modinv(a2, m2)
    t0 = (inv * b2) % m2
    return (t0, m2)

def crt(r1, m1, r2, m2):
    """Combine t ≡ r1 (mod m1) and t ≡ r2 (mod m2). Returns (residue, lcm) or None."""
    g = gcd(m1, m2)
    if (r2 - r1) % g != 0:
        return None
    lcm_val = m1 // g * m2
    _, p, _ = extended_gcd(m1, m2)
    t = (r1 + m1 * ((r2 - r1) // g) * p) % lcm_val
    return (t, lcm_val)

def solve():
    data = sys.stdin.read().split()
    idx = 0
    T = int(data[idx]); idx += 1

    for _ in range(T):
        K, N, M, P, Q = (int(data[idx+i]) for i in range(5))
        idx += 5

        asteroids = []
        for _ in range(K):
            x, y = int(data[idx]), int(data[idx+1])
            idx += 2
            asteroids.append((x, y))

        x0, y0 = asteroids[0]
        lazarbeam = float('inf')
        best_idx = -1

        for i in range(K):
            xi, yi = asteroids[i]
            dx = (xi - x0) % N
            dy = (yi - y0) % M

            # Solve t*Q ≡ dx (mod N)
            res_x = solve_linear_congruence(Q, dx, N)
            if res_x is None:
                continue
            # Solve t*P ≡ dy (mod M)
            res_y = solve_linear_congruence(P, dy, M)
            if res_y is None:
                continue

            t0_x, period_x = res_x
            t0_y, period_y = res_y

            # Combine via CRT
            combined = crt(t0_x, period_x, t0_y, period_y)
            if combined is None:
                continue

            t, period = combined

            # t must be > 0 (laser doesn't hit at step 0)
            if t == 0:
                t = period

            if t < lazarbeam:
                lazarbeam = t
                best_idx = i

        print(best_idx)

def read_your_input():
    return sys.stdin.read()

if __name__ == "__main__":
    solve()
