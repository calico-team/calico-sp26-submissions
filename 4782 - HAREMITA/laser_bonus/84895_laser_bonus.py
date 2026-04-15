import sys
input = sys.stdin.readline

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def modinv(a, m):
    g, x, _ = extended_gcd(a % m, m)
    if g != 1:
        return None
    return x % m

def solve(K, N, M, P, Q, asteroids):
    sx, sy = asteroids[0]
    asteroid_set = {}
    for i, (x, y) in enumerate(asteroids):
        if (x, y) not in asteroid_set:
            asteroid_set[(x, y)] = i

    best_step = None
    best_idx = None

    for i, (x, y) in enumerate(asteroids):
        if i == 0:
            # only hit after wrapping, so step > 0
            pass
        dx = (x - sx) % N
        dy = (y - sy) % M
        # need step t such that t*Q ≡ dx (mod N) and t*P ≡ dy (mod M)
        # solve t*Q ≡ dx (mod N)
        g1, _, _ = extended_gcd(Q, N)
        if dx % g1 != 0:
            continue
        N1 = N // g1
        inv_q = modinv(Q // g1, N1)
        if inv_q is None:
            continue
        t1 = (dx // g1 * inv_q) % N1

        # solve t*P ≡ dy (mod M)
        g2, _, _ = extended_gcd(P, M)
        if dy % g2 != 0:
            continue
        M1 = M // g2
        inv_p = modinv(P // g2, M1)
        if inv_p is None:
            continue
        t2 = (dy // g2 * inv_p) % M1

        # CRT: combine t ≡ t1 (mod N1) and t ≡ t2 (mod M1)
        g3, u, _ = extended_gcd(N1, M1)
        if (t2 - t1) % g3 != 0:
            continue
        lcm = N1 * M1 // g3
        t = (t1 + N1 * ((t2 - t1) // g3 * u % (M1 // g3))) % lcm
        if t == 0:
            t = lcm

        if best_step is None or t < best_step or (t == best_step and i < best_idx):
            best_step = t
            best_idx = i

    return best_idx

T = int(input())
for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    asteroids = []
    for _ in range(K):
        xi, yi = map(int, input().split())
        asteroids.append((xi, yi))
    print(solve(K, N, M, P, Q, asteroids))