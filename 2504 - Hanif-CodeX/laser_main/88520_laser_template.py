import sys
import math

# Increase recursion depth for deep E-GCD calls on large N, M
sys.setrecursionlimit(2000000)

def e_gcd(a, b):
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = e_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y

def mod_inv(a, m):
    gcd, x, y = e_gcd(a, m)
    if gcd != 1:
        return None
    return (x % m + m) % m

def s_l_c(A, B, M):
    """Solves s*A = B (mod M) for s."""
    # Use math.gcd from top-level import for speed
    g = math.gcd(A, M)
    if B % g != 0:
        return None, None
    
    A_red = A // g
    B_red = B // g
    M_red = M // g
    
    inv = mod_inv(A_red, M_red)
    s_start = (B_red * inv) % M_red
    return s_start, M_red

def solve(K, N, M, P, Q, X, Y):
    x0, y0 = X[0], Y[0]
    ms = float('inf')
    idx = -1

    for i in range(K):
        target_x = (X[i] - x0) % N
        target_y = (Y[i] - y0) % M
        
        s1, step1 = s_l_c(Q, target_x, N)
        s2, step2 = s_l_c(P, target_y, M)
        
        if s1 is None or s2 is None:
            continue
            
        # Combine using Chinese Remainder Theorem
        # k*step1 = (s2 - s1) (mod step2)
        k, _ = s_l_c(step1, (s2 - s1) % step2, step2)
        
        if k is not None:
            sc = s1 + k * step1
            if sc == 0:
                # Calculate LCM to find the first wrap-around hit
                lcm = (step1 * step2) // math.gcd(step1, step2)
                sc = lcm
            
            if sc < ms:
                ms = sc
                idx = i
                
    return idx

def main():
    # Use fast I/O for large K across test cases
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
        
        X = []
        Y = []
        for _ in range(K):
            X.append(int(input_data[ptr]))
            Y.append(int(input_data[ptr+1]))
            ptr += 2

        print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
    main()