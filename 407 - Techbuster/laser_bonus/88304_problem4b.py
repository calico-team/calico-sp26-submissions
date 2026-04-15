import sys

def extended_gcd(a, b):
    if a== 0:
        return b, 0, 1
    d, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return d, x, y

def mod_inverse(a, m):
    d, x,y = extended_gcd(a,m)
    if d != 1:
        return None
    return x % m

def solve():
    input_data= sys.stdin.read().split()
    if not input_data:
        return
    
    it = iter(input_data)
    T_str = next(it, None)
    if T_str is None:
        return
    T = int(T_str)
    
    for _ in range(T):
        K =int(next(it))
        N = int(next(it))
        M = int(next(it))
        P= int(next(it))
        Q = int(next(it))
        
        asteroids = []
        for i in range(K):
            x = int(next(it))
            y = int(next(it))
            asteroids.append((x, y))
            
        x0, y0 = asteroids[0]
        min_steps = float('inf')
        best_idx = 0
        
        L = (N * M) // (extended_gcd(N * P, M * Q)[0])
        
        for i in range(K):
            xi, yi = asteroids[i]
            dx = (xi - x0) % N
            dy = (yi - y0) % M
            
            # k * Q = dx (mod N)
            # k * P = dy (mod M)
            
            gq = extended_gcd(Q, N)[0]
            if dx % gq != 0:
                continue
            nq = N // gq
            k_start_q = (dx // gq * mod_inverse(Q // gq, nq)) % nq
            
            gp = extended_gcd(P, M)[0]
            if dy % gp != 0:
                continue
            mp = M // gp
            k_start_p = (dy // gp * mod_inverse(P // gp, mp)) % mp
            
            # k = k_start_q + t * nq
            # k = k_start_p (mod mp)
            # t * nq = (k_start_p - k_start_q) (mod mp)
            
            diff = (k_start_p - k_start_q) % mp
            gn = extended_gcd(nq, mp)[0]
            
            if diff % gn != 0:
                continue
            
            mod_final = mp // gn
            t = (diff // gn * mod_inverse(nq // gn, mod_final)) % mod_final
            k = k_start_q + t * nq
            
            if k == 0 and i == 0:
                lcm_val = (nq * mp) // gn
                k = lcm_val
            elif k == 0 and i != 0:
                k = 0
            
            if k < min_steps:
                min_steps = k
                best_idx = i
                
        print(best_idx)

if __name__ == '__main__':
    solve()