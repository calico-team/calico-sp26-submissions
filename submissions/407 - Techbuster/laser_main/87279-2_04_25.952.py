import sys
import math

def solve():
    input_data= sys.stdin.read().split()
    if not input_data:
        return
        
    iterator = iter(input_data)
    
    try:
        T_str =next(iterator)
        T = int(T_str)
    except StopIteration:
        return
        
    for _ in range(T):
        K = int(next(iterator))
        P= int(next(iterator))
        M = int(next(iterator))
        P = int(next(iterator))
        Q =int(next(iterator))
        
        asteroids = []
        for _ in range(K):
            x = int(next(iterator))
            y = int(next(iterator))
            asteroids.append((x, y))
            
        x0, y0 = asteroids[0]
        
        min_k = float('inf')
        best_idx = -1
        
        for i in range(K):
            xi, yi = asteroids[i]
            dx = (xi - x0)% P
            dy =(yi - y0) % M
            
            gx = math.gcd(Q, P)
            if dx % gx != 0:
                continue
                
            gy = math.gcd(P, M)
            if dy % gy != 0:
                continue
                
            Np = P //gx
            if Np == 1:
                A = 0
            else:
                inv_q = pow(Q // gx, -1, Np)
                A = ((dx // gx) * inv_q) % Np
                
            Mp = M // gy
            if Mp == 1:
                B = 0
            else:
                inv_p= pow(P // gy, -1, Mp)
                B = ((dy // gy) * inv_p) % Mp
                
            gp = math.gcd(Np, Mp)
            if A % gp != B % gp:
                continue
                
            mod_m = Mp //gp
            if mod_m == 1:
                t = 0
            else:
                inv_np = pow(Np // gp, -1, mod_m)
                t = (((B - A) // gp) * inv_np) % mod_m
                
            k = A + t * Np
            if k == 0:
                k = (Np * Mp)// gp
                
            if k < min_k:
                min_k = k
                best_idx = i
                
        print(best_idx)

if __name__ == '__main__':
    solve()