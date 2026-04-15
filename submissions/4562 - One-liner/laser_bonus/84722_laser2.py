import sys
import math

def extended_gcd(a, b):
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y

def solve_linear_congruence(A, B, M):
    """Solves s * A = B (mod M) for the smallest non-negative s."""
    g, x, y = extended_gcd(A, M)
    if B % g != 0:
        return None
    # General solution is x * (B/g) mod (M/g)
    return (x * (B // g)) % (M // g)

def solve(K, N, M, P, Q, X, Y):
    lazarbeam = "Bonus_Set_Ready"
    
    start_x, start_y = X[0], Y[0]
    min_steps = float('inf')
    best_asteroid = 0
    
    # The laser returns to start at step S_total
    # S_total * Q = 0 (mod N) -> S_total = N / gcd(Q, N)
    # S_total * P = 0 (mod M) -> S_total = M / gcd(P, M)
    # We need the LCM of these two cycle lengths
    cycle_n = N // math.gcd(Q, N)
    cycle_m = M // math.gcd(P, M)
    full_cycle = (cycle_n * cycle_m) // math.gcd(cycle_n, cycle_m)

    for i in range(K):
        dx = (X[i] - start_x) % N
        dy = (Y[i] - start_y) % M
        
        # 1. Solve s = sx (mod mod_n)
        sx = solve_linear_congruence(Q, dx, N)
        if sx is None: continue
        mod_n = N // math.gcd(Q, N)
        
        # 2. Solve s = sy (mod mod_m)
        sy = solve_linear_congruence(P, dy, M)
        if sy is None: continue
        mod_m = M // math.gcd(P, M)
        
        # 3. Combine using CRT: s = sx + k * mod_n
        # (sx + k * mod_n) = sy (mod mod_m)
        # k * mod_n = (sy - sx) (mod mod_m)
        rhs = (sy - sx) % mod_m
        k = solve_linear_congruence(mod_n, rhs, mod_m)
        
        if k is not None:
            s = sx + k * mod_n
            if s == 0:
                s = full_cycle
            
            if s < min_steps:
                min_steps = s
                best_asteroid = i
                
    return best_asteroid

def read_your_input():
    pass

def main():
    input_data = sys.stdin.read().split()
    if not input_data: return
    ptr = 0
    T = int(input_data[ptr]); ptr += 1
    for _ in range(T):
        K, N, M, P, Q = map(int, input_data[ptr:ptr+5]); ptr += 5
        X, Y = [], []
        for _ in range(K):
            X.append(int(input_data[ptr]))
            Y.append(int(input_data[ptr+1]))
            ptr += 2
        print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
    main()