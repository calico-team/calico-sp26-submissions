import sys

def extended_gcd(a, b):
    if a == 0:
        return b, 0, 1
    d, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return d, x, y

def solve_linear_congruence(A, B, M):
    g, x0, y0 = extended_gcd(A, M)
    if B % g != 0:
        return None
    mod_step = M // g
    x = (x0 * (B // g)) % mod_step
    return x, mod_step

def solve_crt(r1, m1, r2, m2):
    g, x, y = extended_gcd(m1, m2)
    if (r2 - r1) % g != 0:
        return None
    combined_mod = (m1 * m2) // g
    res = (r1 + m1 * ((r2 - r1) // g * x)) % combined_mod
    return res, combined_mod

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    ptr = 0
    T = int(input_data[ptr])
    ptr += 1
    
    for _ in range(T):
        K = int(input_data[ptr])
        N = int(input_data[ptr+1])
        M = int(input_data[ptr+2])
        P = int(input_data[ptr+3])
        Q = int(input_data[ptr+4])
        ptr += 5
        
        asteroids = []
        for i in range(K):
            asteroids.append((int(input_data[ptr]), int(input_data[ptr+1])))
            ptr += 2
            
        X0, Y0 = asteroids[0]
        min_steps = float('inf')
        lazarbeam = -1
        
        for i in range(K):
            target_x, target_y = asteroids[i]
            dx = (target_x - X0) % N
            dy = (target_y - Y0) % M
            
            sol_x = solve_linear_congruence(Q, dx, N)
            if sol_x is None:
                continue
            
            sol_y = solve_linear_congruence(P, dy, M)
            if sol_y is None:
                continue
            
            combined = solve_crt(sol_x[0], sol_x[1], sol_y[0], sol_y[1])
            
            if combined:
                s_val, period = combined
                if s_val == 0:
                    s_val = period
                
                if s_val < min_steps:
                    min_steps = s_val
                    lazarbeam = i
                    
        sys.stdout.write(str(lazarbeam) + '\n')

def read_your_input():
    return sys.stdin.read().split()

if __name__ == "__main__":
    solve()