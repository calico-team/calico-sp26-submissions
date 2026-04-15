import sys
input = sys.stdin.readline
sys.setrecursionlimit(300000)

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def crt(r1, m1, r2, m2):
    g, p, _ = extended_gcd(m1, m2)
    if (r2 - r1) % g != 0:
        return None
    lcm = m1 // g * m2
    t = (r1 + m1 * ((r2 - r1) // g * p % (m2 // g))) % lcm
    return t, lcm

def solve_t(x0, y0, ax, ay, N, M, P, Q):
    dx = (ax - x0) % N
    g1, p1, _ = extended_gcd(Q, N)
    if dx % g1 != 0:
        return None
    Nx = N // g1
    tx = (dx // g1 * p1) % Nx

    dy = (ay - y0) % M
    g2, p2, _ = extended_gcd(P, M)
    if dy % g2 != 0:
        return None
    My = M // g2
    ty = (dy // g2 * p2) % My

    result = crt(tx, Nx, ty, My)
    if result is None:
        return None
    t, period = result
    if t == 0:
        t = period
    return t

def solve(K, N, M, P, Q, asteroids):
    lazarbeam = None
    x0, y0 = asteroids[0]

    best_t = None
    best_idx = None

    for i in range(K):
        ax, ay = asteroids[i]
        t = solve_t(x0, y0, ax, ay, N, M, P, Q)
        if t is None:
            continue
        if best_t is None or t < best_t:
            best_t = t
            best_idx = i

    return best_idx

def main():
    T = int(input())
    for _ in range(T):
        K, N, M, P, Q = map(int, input().split())
        asteroids = []
        for _ in range(K):
            x, y = map(int, input().split())
            asteroids.append((x, y))
        print(solve(K, N, M, P, Q, asteroids))

main()