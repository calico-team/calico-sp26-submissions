from math import gcd

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def solve_congruence(a, b, m):
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
        rx = solve_congruence(Q, dx, N)
        if not rx: continue
        ry = solve_congruence(P, dy, M)
        if not ry: continue
        res = combine_crt(rx[0], rx[1], ry[0], ry[1])
        if not res: continue
        t, period = res
        if t == 0:
            t = period
        if best_t is None or t < best_t:
            best_t, best_idx = t, i
    return best_idx

def main():
    T = int(input())
    for _ in range(T):
        line = input().split()
        K, N, M, P, Q = int(line[0]), int(line[1]), int(line[2]), int(line[3]), int(line[4])
        X, Y = [], []
        for _ in range(K):
            coords = input().split()
            X.append(int(coords[0]))
            Y.append(int(coords[1]))
        print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
    main()