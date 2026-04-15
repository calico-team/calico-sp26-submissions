import sys
import math

def egcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = egcd(b, a % b)
    return g, y1, x1 - (a // b) * y1

def modinv(a, m):
    g, x, _ = egcd(a, m)
    return x % m if g == 1 else None

def solve_cong(a, b, m):
    g = math.gcd(a, m)
    if b % g != 0:
        return None, None
    a1, b1, m1 = a // g, b // g, m // g
    inv = modinv(a1, m1)
    return (inv * b1) % m1, m1

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    T = int(next(it))
    
    for _ in range(T):
        K = int(next(it))
        N = int(next(it))
        M = int(next(it))
        P = int(next(it))
        Q = int(next(it))
        
        asteroids = []
        for _ in range(K):
            asteroids.append((int(next(it)), int(next(it))))
        
        x0, y0 = asteroids[0]
        best_t = float('inf')
        best_idx = 0
        
        for i, (xi, yi) in enumerate(asteroids):
            tx, mod_x = solve_cong(Q, (xi - x0) % N, N)
            ty, mod_y = solve_cong(P, (yi - y0) % M, M)
            
            if tx is None or ty is None:
                continue
            
            g = math.gcd(mod_x, mod_y)
            if (ty - tx) % g != 0:
                continue
            
            t = tx
            while t % mod_y != ty % mod_y:
                t += mod_x
            
            if t == 0:
                t = mod_x * mod_y // math.gcd(mod_x, mod_y)
            
            if t < best_t or (t == best_t and i < best_idx):
                best_t = t
                best_idx = i
        
        print(best_idx)

if __name__ == "__main__":
    solve()