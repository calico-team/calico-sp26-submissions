
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = extended_gcd(b, a % b)
    return g, y1, x1 - (a // b) * y1

def modinv(a, m):
    g, x, y = extended_gcd(a, m)
    return x % m

def crt(r1, m1, r2, m2):
    # 解 t ≡ r1 (mod m1), t ≡ r2 (mod m2)
    g, x, y = extended_gcd(m1, m2)
    if (r2 - r1) % g != 0:
        return -1, -1
    lcm = m1 // g * m2
    t = r1 + m1 * (((r2 - r1) // g * x) % (m2 // g))
    t = t % lcm
    if t == 0:
        t = lcm
    return t, lcm

T = int(input())
for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    
    asteroids = []
    for i in range(K):
        x, y = map(int, input().split())
        asteroids.append((x, y, i))
    
    x0, y0, _ = asteroids[0]
    
    best_t = 10**18
    best_idx = -1
    
    for i in range(1, K):
        xi, yi, idx = asteroids[i]
        
        dx = (xi - x0) % N
        gx = gcd(Q, N)
        if dx % gx != 0:
            continue
        m1 = N // gx
        r1 = (modinv(Q // gx, m1) * (dx // gx)) % m1
        
        dy = (yi - y0) % M
        gy = gcd(P, M)
        if dy % gy != 0:
            continue
        m2 = M // gy
        r2 = (modinv(P // gy, m2) * (dy // gy)) % m2
        
        t, lcm = crt(r1, m1, r2, m2)
        if t == -1:
            continue
        
        if t < best_t:
            best_t = t
            best_idx = idx
    
    print(best_idx)
