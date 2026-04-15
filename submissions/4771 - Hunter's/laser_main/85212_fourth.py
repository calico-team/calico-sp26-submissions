import math

def solve():
    T = int(input())
    for _ in range(T):
        K, N, M, P, Q = map(int, input().split())
        asteroids = []
        for i in range(K):
            x, y = map(int, input().split())
            asteroids.append((x, y, i))
        
        start_x, start_y, _ = asteroids[0]
        pos_to_index = {}
        for i in range(1, K):
            x, y, idx = asteroids[i]
            pos_to_index[(x, y)] = idx        
        min_t = None
        min_idx = None
        
        for x, y, idx in asteroids[1:]:
            dx = (x - start_x) % N
            dy = (y - start_y) % M
            g1 = math.gcd(Q, N)
            if dx % g1 != 0:
                continue
            N1 = N // g1
            Q1 = Q // g1
            dx1 = dx // g1
            try:
                inv1 = pow(Q1, -1, N1)
            except ValueError:
                continue
            t1 = (dx1 * inv1) % N1
            g2 = math.gcd(P, M)
            if dy % g2 != 0:
                continue
            M2 = M // g2
            P2 = P // g2
            dy2 = dy // g2
            try:
                inv2 = pow(P2, -1, M2)
            except ValueError:
                continue
            t2 = (dy2 * inv2) % M2
            def crt(a1, m1, a2, m2):
                g = math.gcd(m1, m2)
                if (a2 - a1) % g != 0:
                    return None, None
                lcm = m1 // g * m2
                x, y = extended_gcd(m1, m2)
                diff = a2 - a1
                diff //= g
                m1g = m1 // g
                m2g = m2 // g
                inv_m1g = pow(m1g, -1, m2g)
                k = (diff * inv_m1g) % m2g
                t = a1 + m1 * k
                return t % lcm, lcm
            
            def extended_gcd(a, b):
                if b == 0:
                    return 1, 0
                x1, y1 = extended_gcd(b, a % b)
                return y1, x1 - (a // b) * y1
            
            t, lcm = crt(t1, N1, t2, M2)
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