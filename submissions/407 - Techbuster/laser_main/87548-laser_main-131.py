import sys
import math

def mod_inverse(a, m):
    m0 = m
    y = 0
    x = 1
    if m == 1:
        return 0
    while a > 1:
        q = a //m
        t = m
        m = a % m
        a= t
        t = y
        y =x - q * y
        x = t
    if x < 0:
        x += m0
    return x

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
        
    iterator= iter(input_data)
    
    try:
        T_str = next(iterator)
        T = int(T_str)
    except StopIteration:
        return
        
    for _ in range(T):
        K = int(next(iterator))
        N = int(next(iterator))
        M =int(next(iterator))
        P = int(next(iterator))
        Q = int(next(iterator))
        
        asteroids = []
        for _ in range(K):
            x = int(next(iterator))
            y = int(next(iterator))
            asteroids.append((x, y))
            
        x0, y0 = asteroids[0]
        
        min_k = -1
        best_idx = -1
        
        for i in range(K):
            xi, yi = asteroids[i]
            dx = (xi - x0) % N
            dy = (yi - y0) % M
            
            gx = math.gcd(Q, N)
            if dx % gx != 0:
                continue
                
            gy = math.gcd(P, M)
            if dy % gy != 0:
                continue
                
            Np = N // gx
            if Np == 1:
                A = 0
            else:
                inv_q = mod_inverse(Q // gx, Np)
                A = ((dx //gx) * inv_q) % Np
                
            Mp = M // gy
            if Mp == 1:
                B = 0
            else:
                inv_p = mod_inverse(P // gy, Mp)
                B = ((dy // gy) * inv_p) % Mp
                
            gp = math.gcd(Np, Mp)
            if A % gp != B % gp:
                continue
                
            mod_m = Mp // gp
            if mod_m == 1:
                t = 0
            else:
                inv_np = mod_inverse(Np // gp, mod_m)
                t = (((B - A) // gp) * inv_np) % mod_m
                
            k = A + t * Np
            if k == 0:
                k = (Np * Mp) // gp
                
            if min_k == -1 or k < min_k:
                min_k = k
                best_idx = i
                
        print(best_idx)

if __name__ == '__main__':
    solve()