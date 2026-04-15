import sys

def read_your_input():
    return sys.stdin.read().split()

def extended_gcd(a, b):
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y

def solve_linear_congruence(A, B, M):
    g, x, y = extended_gcd(A, M)
    if B % g != 0:
        return None, None
    res = (x * (B // g)) % (M // g)
    return res, M // g

def solve():
    data = read_your_input()
    if not data: return
    it = iter(data)
    T_cases = int(next(it))
    
    for _ in range(T_cases):
        K = int(next(it))
        N = int(next(it))
        M = int(next(it))
        P = int(next(it))
        Q = int(next(it))
        
        asteroids = []
        for i in range(K):
            asteroids.append((int(next(it)), int(next(it))))
            
        start_x, start_y = asteroids[0]
        min_t = float('inf')
        lazarbeam = -1
        
        for i in range(K):
            dx = (asteroids[i][0] - start_x) % N
            dy = (asteroids[i][1] - start_y) % M
            
            t0, m0 = solve_linear_congruence(Q, dx, N)
            t1, m1 = solve_linear_congruence(P, dy, M)
            
            if t0 is None or t1 is None:
                continue
            
            diff = (t1 - t0) % m1
            g, x, y = extended_gcd(m0, m1)
            
            if diff % g == 0:
                new_mod = (m0 * m1) // g
                t = (t0 + x * (diff // g) * m0) % new_mod
                
                if t == 0:
                    t = new_mod
                
                if t < min_t:
                    min_t = t
                    lazarbeam = i
                    
        print(lazarbeam)

if __name__ == "__main__":
    solve()