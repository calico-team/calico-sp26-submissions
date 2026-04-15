import math

def extended_gcd(a, b):
    if a == 0:
        return (b, 0, 1)
    g, y, x = extended_gcd(b % a, a)
    return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, _ = extended_gcd(a, m)
    if g != 1:
        return None
    return x % m

def crt(a1, m1, a2, m2):
    g = math.gcd(m1, m2)
    if (a1 - a2) % g != 0:
        return None
    m1p = m1 // g
    m2p = m2 // g
    rhs = (a2 - a1) // g
    inv = modinv(m1p, m2p)
    if inv is None:
        return None
    k = (rhs * inv) % m2p
    t = a1 + k * m1
    lcm = m1 // g * m2
    return (t % lcm, lcm)

def solve(K, N, M, P, Q, X, Y):
    x0, y0 = X[0], Y[0]

    gx = math.gcd(Q, N)
    gy = math.gcd(P, M)
    Np = N // gx
    Mp = M // gy

    invQ = modinv(Q // gx, Np)
    invP = modinv(P // gy, Mp)
    period = Np // math.gcd(Np, Mp) * Mp

    best_t = period
    best_idx = 0

    for i in range(1, K):
        dx = (X[i] - x0) % N
        dy = (Y[i] - y0) % M

        if dx % gx != 0 or dy % gy != 0:
            continue

        a = ((dx // gx) * invQ) % Np
        b = ((dy // gy) * invP) % Mp

        res = crt(a, Np, b, Mp)
        if res is None:
            continue

        t0, lcm = res
        t = lcm if t0 == 0 else t0

        if t < best_t or (t == best_t and i < best_idx):
            best_t = t
            best_idx = i

    return best_idx

def main():
    T = int(input())
    for _ in range(T):
        line = input().split()
        K = int(line[0])
        N = int(line[1])
        M = int(line[2])
        P = int(line[3])
        Q = int(line[4])

        X = []
        Y = []
        for _ in range(K):
            coords = input().split()
            X.append(int(coords[0]))
            Y.append(int(coords[1]))

        print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
    main()