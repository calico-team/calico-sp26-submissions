from math import gcd

def ext_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = ext_gcd(b, a % b)
    return g, y, x - (a // b) * y

def mod_inv(a, m):
    g, x, _ = ext_gcd(a % m, m)
    if g != 1:
        return None  # no inverse
    return x % m

def solve_linear_congruence(a, b, m):
    # solve a*t ≡ b (mod m), returns (t0, step) or None
    g = gcd(a, m)
    if b % g != 0:
        return None
    a2, b2, m2 = a // g, b // g, m // g
    inv = mod_inv(a2, m2)
    t0 = (b2 * inv) % m2
    return t0, m2

def crt(r1, m1, r2, m2):
    # find t ≡ r1 (mod m1) and t ≡ r2 (mod m2)
    g, p, q = ext_gcd(m1, m2)
    if (r2 - r1) % g != 0:
        return None
    lcm = m1 * m2 // g
    t = (r1 + m1 * ((r2 - r1) // g * p % (m2 // g))) % lcm
    return t, lcm

def first_hit_time(ax, ay, start_x, start_y, N, M, P, Q):
    dx = (ax - start_x) % N
    dy = (ay - start_y) % M

    # t*Q ≡ dx (mod N)
    res_x = solve_linear_congruence(Q, dx, N)
    # t*P ≡ dy (mod M)
    res_y = solve_linear_congruence(P, dy, M)

    if res_x is None or res_y is None:
        return None

    t_x, mod_x = res_x
    t_y, mod_y = res_y

    combined = crt(t_x, mod_x, t_y, mod_y)
    if combined is None:
        return None

    t, mod = combined
    if t == 0:
        t = mod  # laser doesn't hit start until it wraps
    return t

def solve(K, N, M, P, Q, asteroids):
    start_x, start_y = asteroids[0]
    best_t = None
    best_idx = -1

    for i in range(1, K):
        ax, ay = asteroids[i]
        t = first_hit_time(ax, ay, start_x, start_y, N, M, P, Q)
        if t is not None and (best_t is None or t < best_t):
            best_t = t
            best_idx = i

    # check if laser returns to start (index 0)
    t0 = first_hit_time(start_x, start_y, start_x, start_y, N, M, P, Q)
    if t0 is not None and (best_t is None or t0 <= best_t):
        # only pick index 0 if it comes strictly before or ties with nothing else
        if best_t is None or t0 < best_t:
            best_idx = 0

    return best_idx

T = int(input())
for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    asteroids = []
    for _ in range(K):
        x, y = map(int, input().split())
        asteroids.append((x, y))
    print(solve(K, N, M, P, Q, asteroids))