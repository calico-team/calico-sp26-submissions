from math import gcd

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def modinv(a, m):
    if m == 1:
        return 0
    g, x, _ = extended_gcd(a % m, m)
    return x % m if g == 1 else None

def crt(r1, m1, r2, m2):
    # Find t ≡ r1 (mod m1) and t ≡ r2 (mod m2)
    g = gcd(m1, m2)
    if (r2 - r1) % g != 0:
        return None
    lcm = m1 // g * m2
    m2g = m2 // g
    inv = modinv((m1 // g) % m2g, m2g)
    if inv is None:
        return None
    k = ((r2 - r1) // g * inv) % m2g
    return (r1 + m1 * k) % lcm, lcm

def min_t(dx, dy, Q, N, P, M):
    # Solve t*Q ≡ dx (mod N)
    g1 = gcd(Q, N)
    if dx % g1 != 0:
        return None
    period1 = N // g1
    inv1 = modinv((Q // g1) % period1, period1)
    if inv1 is None:
        return None
    t1 = (dx // g1 * inv1) % period1

    # Solve t*P ≡ dy (mod M)
    g2 = gcd(P, M)
    if dy % g2 != 0:
        return None
    period2 = M // g2
    inv2 = modinv((P // g2) % period2, period2)
    if inv2 is None:
        return None
    t2 = (dy // g2 * inv2) % period2

    result = crt(t1, period1, t2, period2)
    return result[0] if result is not None else None

def solve(K, N, M, P, Q, X, Y):
    x0, y0 = X[0], Y[0]
    best_t, best_idx = None, None

    # Check asteroids 1..K-1 (t=0 allowed: hit immediately if same position)
    for i in range(1, K):
        dx = (X[i] - x0) % N
        dy = (Y[i] - y0) % M
        t = min_t(dx, dy, Q, N, P, M)
        if t is None:
            continue
        if best_t is None or t < best_t or (t == best_t and i < best_idx):
            best_t, best_idx = t, i

    # Check asteroid 0: must wrap fully (t > 0), min t = lcm(N/gcd(Q,N), M/gcd(P,M))
    p1 = N // gcd(Q, N)
    p2 = M // gcd(P, M)
    t0 = p1 // gcd(p1, p2) * p2
    if best_t is None or t0 < best_t or (t0 == best_t and 0 < best_idx):
        best_t, best_idx = t0, 0

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