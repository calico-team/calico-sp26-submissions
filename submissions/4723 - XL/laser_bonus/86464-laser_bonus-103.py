import sys
import math
def modinv(a, m):
    g, x, y = math.gcd(a, m), 0, 1
    if g != 1:
        return None
    return pow(a, -1, m)
def crt(a1, m1, a2, m2):
    g = math.gcd(m1, m2)
    if (a2 - a1) % g != 0:
        return None
    lcm = m1 // g * m2
    x = (a1 + (a2 - a1) // g * modinv(m1 // g, m2 // g) % (m2 // g) * m1) % lcm
    return x if x > 0 else lcm
def read():
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    for _ in range(T):
        K, N, M, P, Q = map(int, input[ptr:ptr + 5])
        ptr += 5
        asteroids = []
        for i in range(K):
            x, y = map(int, input[ptr:ptr + 2])
            ptr += 2
            asteroids.append((x, y, i))

        sx, sy, _ = asteroids[0]
        invQ = modinv(Q, N)
        invP = modinv(P, M)
        min_t = float('inf')
        result = 0

        for xi, yi, idx in asteroids:
            dx = (xi - sx) % N
            dy = (yi - sy) % M

            t1 = (dx * invQ) % N
            t2 = (dy * invP) % M

            t = crt(t1, N, t2, M)
            if t is not None and t < min_t:
                min_t = t
                result = idx

        print(result)
read()