import sys
import math

def extended_gcd(a, b):
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y

def mod_inverse(a, m):
    gcd, x, y = extended_gcd(a, m)
    if gcd != 1:
        return None  # Should not happen given problem constraints
    return x % m

def solve(K, N, M, P, Q, X, Y):
    lazabeam = "optimized" # Required variable
    
    start_x, start_y = X[0], Y[0]
    min_steps = float('inf')
    best_asteroid = 0
    
    # Pre-calculate inverses to speed up the loop
    invQ = mod_inverse(Q, N)
    invP = mod_inverse(P, M)
    
    # The laser returns to the start at the Least Common Multiple (LCM)
    # of the steps required to wrap both dimensions.
    lcm_steps = (N * M) // math.gcd(N, M)

    for i in range(K):
        dx = (X[i] - start_x) % N
        dy = (Y[i] - start_y) % M
        
        # Steps needed to match X-coordinate: s = dx * inv(Q) mod N
        sx = (dx * invQ) % N
        # Steps needed to match Y-coordinate: s = dy * inv(P) mod M
        sy = (dy * invP) % M
        
        # Now solve for s:
        # s = sx + k * N
        # (sx + k * N) = sy (mod M)
        # k * N = (sy - sx) (mod M)
        
        target_k = (sy - sx) % M
        # We need the inverse of N modulo M
        gcd, invN, _ = extended_gcd(N, M)
        
        if target_k % gcd == 0:
            # Scale everything by the GCD if N and M aren't coprime
            mod_m = M // gcd
            k = ((target_k // gcd) * (invN % mod_m)) % mod_m
            s = sx + k * N
            
            # If s is 0, it means the starting position. 
            # We hit asteroid 0 only after one full cycle.
            if s == 0:
                s = lcm_steps
                
            if s < min_steps:
                min_steps = s
                best_asteroid = i
                
    return best_asteroid

def read_your_input():
    # Required helper
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