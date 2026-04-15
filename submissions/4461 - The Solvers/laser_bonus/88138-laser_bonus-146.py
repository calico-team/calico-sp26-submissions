from math import gcd

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0

    g, x1, y1 = extended_gcd(b, a % b)
    
    x = y1
    y = x1 - (a // b) * y1

    return g, x, y


def crt_solve(r1, m1, r2, m2):
    g, inv, _ = extended_gcd(m1, m2)

    # No solution case
    if (r2 - r1) % g != 0:
        return None

    lcm = (m1 // g) * m2

    temp = (r2 - r1) // g
    temp = (temp * inv) % (m2 // g)

    t = (r1 + m1 * temp) % lcm

    return t, lcm


def solve(K, N, M, P, Q, X, Y):
    start_x = X[0]
    start_y = Y[0]

    best_time = float('inf')
    answer_index = 0

    for i in range(1, K):
        dx = (X[i] - start_x) % N
        dy = (Y[i] - start_y) % M

        g1, inv1, _ = extended_gcd(Q, N)

        if dx % g1 != 0:
            continue

        mod1 = N // g1
        r1 = (dx // g1 * inv1) % mod1

        g2, inv2, _ = extended_gcd(P, M)

        if dy % g2 != 0:
            continue

        mod2 = M // g2
        r2 = (dy // g2 * inv2) % mod2

       
        res = crt_solve(r1, mod1, r2, mod2)

        if res is None:
            continue

        t, _ = res

        if t == 0:
            continue  

        if t < best_time:
            best_time = t
            answer_index = i

    return answer_index