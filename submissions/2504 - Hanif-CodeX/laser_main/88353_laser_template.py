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
        return None  # No inverse exists
    return (x % m + m) % m

def s_l_c(A, B, M):
    """Solves s*A = B (mod M) for s."""
    import math
    gcd = math.gcd(A, M)
    if B % gcd != 0:
        return None, None
    
    # Reduce the equation: s * (A/gcd) = (B/gcd) (mod M/gcd)
    A_red = A // gcd
    B_red = B // gcd
    M_red = M // gcd
    
    # s = (B/gcd) * inv(A/gcd, M/gcd) (mod M/gcd)
    inv = mod_inv(A_red, M_red)
    s_start = (B_red * inv) % M_red
    return s_start, M_red

def solve(K, N, M, P, Q, X, Y):
    x0, y0 = X[0], Y[0]
    ms = float('inf')
    idx = -1

    for i in range(K):
        # Target: s*Q = (Xi - X0) mod N AND s*P = (Yi - Y0) mod M
        target_x = (X[i] - x0) % N
        target_y = (Y[i] - y0) % M
        
        # Solve individually
        s1, step1 = s_l_c(Q, target_x, N)
        s2, step2 = s_l_c(P, target_y, M)
        
        if s1 is None or s2 is None:
            continue
            
        # Combine using Chinese Remainder Theorem:
        # s = s1 (mod step1)
        # s = s2 (mod step2)
        # Which is: s = s1 + k*step1, so (s1 + k*step1) = s2 (mod step2)
        # k*step1 = (s2 - s1) (mod step2)
        k, cs = s_l_c(step1, (s2 - s1) % step2, step2)
        
        if k is not None:
            sc = s1 + k * step1
            # If s is 0, it's the starting asteroid; must wrap around once.
            if sc == 0:
                import math
                lcm = (step1 * step2) // math.gcd(step1, step2)
                sc = lcm
            
            if sc < ms:
                ms = sc
                idx = i
                
    return idx