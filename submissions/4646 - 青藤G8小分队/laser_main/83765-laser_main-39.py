def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def modinv(a, m):
    g, x, y = extended_gcd(a, m)
    if g != 1:
        return None
    return x % m

def solve_congruence(a1, m1, a2, m2):
    g, x, y = extended_gcd(m1, m2)
    if (a2 - a1) % g != 0:
        return None, None
    
    lcm = m1 // g * m2
    tmp = (a2 - a1) // g
    tmp = tmp * x % (m2 // g)
    a = (a1 + tmp * m1) % lcm
    return a, lcm

def solve():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    
    for _ in range(T):
        K = int(input[ptr])
        N = int(input[ptr+1])
        M = int(input[ptr+2])
        P = int(input[ptr+3])
        Q = int(input[ptr+4])
        ptr += 5
        
        asteroids = []
        for __ in range(K):
            x = int(input[ptr])
            y = int(input[ptr+1])
            asteroids.append((x, y))
            ptr += 2
        
        x0, y0 = asteroids[0]
        min_time = float('inf')
        result = 0
        
        for i in range(K):
            xi, yi = asteroids[i]
            if i == 0:
                continue
            
            # 激光移动t步后的位置：
            # x = (x0 + Q*t) mod N
            # y = (y0 + P*t) mod M
            # 要等于 (xi, yi)
            
            # 解同余方程:
            # Q*t ≡ (xi - x0) mod N
            # P*t ≡ (yi - y0) mod M
            
            a1 = (xi - x0) % N
            m1 = N
            a2 = (yi - y0) % M
            m2 = M
            
            # 计算t的可能值
            # 对于第一个方程：t ≡ a1 * Q^{-1} mod N
            # 对于第二个方程：t ≡ a2 * P^{-1} mod M
            
            g1, x1, y1 = extended_gcd(Q, N)
            g2, x2, y2 = extended_gcd(P, M)
            
            if a1 % g1 != 0 or a2 % g2 != 0:
                continue
            
            t1 = (x1 * (a1 // g1)) % (N // g1)
            t2 = (x2 * (a2 // g2)) % (M // g2)
            
            m1_new = N // g1
            m2_new = M // g2
            
            t, lcm = solve_congruence(t1, m1_new, t2, m2_new)
            if t is not None and t > 0:
                if t < min_time:
                    min_time = t
                    result = i
        
        if min_time == float('inf'):
            print(0)
        else:
            print(result)

if __name__ == "__main__":
    solve()
