import math

def find_coeffs(a, b):
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = find_coeffs(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y

def solve_linear_congruence(A, B, M):
    g, x, y = find_coeffs(A, M)
    if B % g != 0:
        return None, None
    mod = M // g
    t0 = (x * (B // g)) % mod
    return t0, mod

T = int(input())
for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    asteroids = []
    for _ in range(K):
        x, y = map(int, input().split())
        asteroids.append((x, y))
    
    x0, y0 = asteroids[0] 
    min_t = float('inf')
    result_idx = -1

    for i in range(K):
        xi, yi = asteroids[i]
        dx = (xi - x0) % N
        dy = (yi - y0) % M
        
        tx, mod_x = solve_linear_congruence(Q, dx, N)
        if tx is None: 
            continue
        
        ty, mod_y = solve_linear_congruence(P, dy, M)
        if ty is None: 
            continue
        
        rhs = (ty - tx) % mod_y
        k, mod_k = solve_linear_congruence(mod_x, rhs, mod_y)
        
        if k is not None:
            combined_mod = mod_x * mod_k
            t_final = (tx + k * mod_x) % combined_mod
            
            if t_final == 0:
                t_final = combined_mod
            
            if t_final < min_t:
                min_t = t_final
                result_idx = i

    print(result_idx)

