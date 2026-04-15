def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def solve_linear_congruence(a, b, m):
    g, x, _ = extended_gcd(a % m, m)
    if b % g != 0:
        return None
    m //= g
    r = (b // g) * x % m
    return r, m

def combine_congruences(r1, m1, r2, m2):
    diff = (r2 - r1) % m2
    sol = solve_linear_congruence(m1, diff, m2)
    if sol is None:
        return None
    k, mod = sol
    r = r1 + m1 * k
    lcm = m1 * mod
    return r % lcm, lcm

T = int(input())
for _ in range(T):
    K, N, M, P, Q = map(int, input().split())

    asteroids = []
    for i in range(K):
        x, y = map(int, input().split())
        asteroids.append((x, y))

    X0, Y0 = asteroids[0]

    best_t = None
    best_idx = None

    for i in range(K):
        Xi, Yi = asteroids[i]
        dx = (Xi - X0) % N
        dy = (Yi - Y0) % M

        sol1 = solve_linear_congruence(Q, dx, N)
        sol2 = solve_linear_congruence(P, dy, M)

        if sol1 is None or sol2 is None:
            continue

        r1, m1 = sol1
        r2, m2 = sol2

        combined = combine_congruences(r1, m1, r2, m2)
        if combined is None:
            continue

        r, mod = combined
        if r == 0:
            r = mod

        if best_t is None or r < best_t:
            best_t = r
            best_idx = i

    print(best_idx)
