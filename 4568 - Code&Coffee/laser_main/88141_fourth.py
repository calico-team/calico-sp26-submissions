import math

def modinv(a, m):
    g, x, y = extended_gcd(a, m)
    if g != 1:
        return None
    return x % m

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = extended_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1

def crt_solve(t1, m1, t2, m2):
    g = math.gcd(m1, m2)
    if (t2 - t1) % g != 0:
        return None, None
    m1g = m1 // g
    m2g = m2 // g
    diff = (t2 - t1) // g
    inv = modinv(m1g, m2g)
    if inv is None:
        return None, None
    k = (diff * inv) % m2g
    t = t1 + m1 * k
    lcm = m1 // g * m2
    return t % lcm, lcm

def solve():
    T = int(input())
    for _ in range(T):
        K, N, M, P, Q = map(int, input().split())
        asteroids = []
        for i in range(K):
            x, y = map(int, input().split())
            asteroids.append((x, y))
        
        start_x, start_y = asteroids[0]
        
        min_t = None
        min_idx = None
        
        for idx in range(1, K):
            x, y = asteroids[idx]
            dx = (x - start_x) % N
            dy = (y - start_y) % M
            
            g1 = math.gcd(Q, N)
            if dx % g1 != 0:
                continue
            N1 = N // g1
            Q1 = Q // g1
            dx1 = dx // g1
            inv1 = modinv(Q1, N1)
            if inv1 is None:
                continue
            t1 = (dx1 * inv1) % N1
            g2 = math.gcd(P, M)
            if dy % g2 != 0:
                continue
            M2 = M // g2
            P2 = P // g2
            dy2 = dy // g2
            inv2 = modinv(P2, M2)
            if inv2 is None:
                continue
            t2 = (dy2 * inv2) % M2
            t, lcm = crt_solve(t1, N1, t2, M2)
            if t is None:
                continue
            
            if t == 0:
                t = lcm
            
            if min_t is None or t < min_t:
                min_t = t
                min_idx = idx
        
        print(min_idx)

if __name__ == "__main__":
    solve()