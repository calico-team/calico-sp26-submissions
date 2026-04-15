import sys
from math import gcd

def solve_linear(a, b, m):
    g = gcd(a, m)
    if b % g != 0:
        return None
    a1 = a // g
    m1 = m // g
    b1 = b // g
    if m1 == 1:
        return 0, 1
    inv = pow(a1, -1, m1)
    r = (b1 * inv) % m1
    return r, m1

def solve_two_congruences(r1, d1, r2, d2):
    g = gcd(d1, d2)
    if (r2 - r1) % g != 0:
        return None
    target = (r2 - r1) % d2
    gg = g
    d1g = d1 // gg
    d2g = d2 // gg
    targetg = target // gg
    if d2g == 1:
        u0 = 0
    else:
        inv = pow(d1g, -1, d2g)
        u0 = (targetg * inv) % d2g
    k_base = r1 + d1 * u0
    L = d1 * d2g
    k_part = k_base % L
    return k_part, L

input = sys.stdin.read
data = input().split()

index = 0
T = int(data[index])
index += 1

for _ in range(T):
    K = int(data[index])
    N = int(data[index + 1])
    M = int(data[index + 2])
    P = int(data[index + 3])
    Q = int(data[index + 4])
    index += 5

    asteroids = []
    for i in range(K):
        X = int(data[index])
        Y = int(data[index + 1])
        asteroids.append((X, Y))
        index += 2

    sx, sy = asteroids[0]

    min_k = float('inf')
    best_idx = -1

    for j in range(K):
        Xj, Yj = asteroids[j]
        dx = (Xj - sx) % N
        dy = (Yj - sy) % M

        res1 = solve_linear(Q, dx, N)
        if res1 is None:
            continue
        r1, d1 = res1

        res2 = solve_linear(P, dy, M)
        if res2 is None:
            continue
        r2, d2 = res2

        res_crt = solve_two_congruences(r1, d1, r2, d2)
        if res_crt is None:
            continue
        k_part, L = res_crt

        this_k = L if k_part == 0 else k_part

        if this_k < min_k:
            min_k = this_k
            best_idx = j
        elif this_k == min_k:
            if j < best_idx:
                best_idx = j

    print(best_idx)