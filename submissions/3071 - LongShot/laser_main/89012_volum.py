def solve_case(K, N, M, P, Q, asteroids):
    """
    Returns the index of the first asteroid hit by the laser.
    """
    # Starting position is the first asteroid
    x0, y0 = asteroids[0]
    
    # We need to find the smallest t > 0 such that:
    # (x0 + t*Q) mod N == Xi and (y0 + t*P) mod M == Yi for some asteroid i
    # But since asteroids are given as indices, we check in order
    
    # Precompute the sequence of laser positions until it returns to start
    # The laser path is periodic with period = LCM(N, M) / GCD(Q, N) / GCD(P, M)?
    # Actually simpler: simulate until we return to (x0, y0) mod (N, M)
    # But that could be up to LCM(N, M) which is too large.
    # We need a better approach.
    
    # For each asteroid, check if it lies on the laser's path.
    # The laser's path: (x0 + t*Q) mod N, (y0 + t*P) mod M for t = 0,1,2,...
    # We want the smallest t > 0 for which this equals (Xi, Yi) for some i.
    
    # Since P and Q are coprime to N and M respectively? Not necessarily.
    # But we can solve for t modulo N and modulo M:
    # t*Q ≡ (Xi - x0) mod N  => t ≡ (Xi - x0) * inv(Q mod N) mod (N / gcd(Q,N))
    # similarly for M.
    # Then t must satisfy both congruences, so we solve using CRT.
    
    # However, we only need the first asteroid hit, so we can compute for each asteroid
    # the smallest t that hits it, and take the minimum t > 0.
    
    from math import gcd
    
    def solve_t(x0, y0, xi, yi, N, M, P, Q):
        # Find smallest t >= 0 such that:
        # (x0 + t*Q) % N == xi
        # (y0 + t*P) % M == yi
        # Returns (t, True) if solution exists, else (-1, False)
        
        # Equation 1: t*Q ≡ dx (mod N) where dx = (xi - x0) % N
        dx = (xi - x0) % N
        dy = (yi - y0) % M
        
        g1 = gcd(Q, N)
        if dx % g1 != 0:
            return -1, False
        # Divide through
        N1 = N // g1
        Q1 = Q // g1
        dx1 = dx // g1
        # Now solve t*Q1 ≡ dx1 (mod N1) with gcd(Q1, N1)=1
        # Find inverse of Q1 modulo N1
        inv_Q1 = pow(Q1, -1, N1)
        t1 = (dx1 * inv_Q1) % N1  # This is t modulo N1
        
        # Equation 2: t*P ≡ dy (mod M)
        g2 = gcd(P, M)
        if dy % g2 != 0:
            return -1, False
        M2 = M // g2
        P2 = P // g2
        dy2 = dy // g2
        inv_P2 = pow(P2, -1, M2)
        t2 = (dy2 * inv_P2) % M2  # t modulo M2
        
        # Now we have t ≡ t1 (mod N1) and t ≡ t2 (mod M2)
        # Solve using CRT
        g = gcd(N1, M2)
        if (t2 - t1) % g != 0:
            return -1, False
        
        # Solve: t = t1 + N1 * k
        # t ≡ t2 (mod M2) => t1 + N1*k ≡ t2 (mod M2) => N1*k ≡ t2 - t1 (mod M2)
        N1g = N1 // g
        M2g = M2 // g
        rhs = ((t2 - t1) // g) % M2g
        inv_N1g = pow(N1g, -1, M2g)
        k = (rhs * inv_N1g) % M2g
        
        t = t1 + N1 * k
        # t is the smallest non-negative solution
        if t == 0:
            # t=0 corresponds to the starting asteroid (index 0)
            # But we want the first hit after starting, so if t=0, it's not valid
            # unless we're checking asteroid 0 itself at time 0
            # For asteroid 0, we need t > 0
            if xi == x0 and yi == y0:
                # Find the period: smallest T > 0 such that returns to start
                # That's the lcm of the periods in x and y
                period_x = N // g1
                period_y = M // g2
                T = period_x * period_y // gcd(period_x, period_y)
                if T == 0:
                    T = 1
                # The next time it hits start is at t = T
                return T, True
            else:
                # For other asteroids, t=0 means they're at start? No, start is asteroid 0.
                # If Xi != x0 or Yi != y0, then t=0 can't satisfy both anyway
                # So this case shouldn't happen for other asteroids
                return t, True
        return t, True
    
    best_t = None
    best_idx = -1
    
    # Check asteroid 0 (starting position) - it gets hit after the period
    period_x = N // gcd(Q, N)
    period_y = M // gcd(P, M)
    period = period_x * period_y // gcd(period_x, period_y)
    if period > 0:
        best_t = period
        best_idx = 0
    
    # Check other asteroids
    for i in range(1, K):
        xi, yi = asteroids[i]
        t, exists = solve_t(x0, y0, xi, yi, N, M, P, Q)
        if exists and t > 0:
            if best_t is None or t < best_t:
                best_t = t
                best_idx = i
    
    return best_idx


def solve():
    import sys
    data = sys.stdin.read().strip().split()
    it = iter(data)
    T = int(next(it))
    results = []
    for _ in range(T):
        K = int(next(it))
        N = int(next(it))
        M = int(next(it))
        P = int(next(it))
        Q = int(next(it))
        asteroids = []
        for __ in range(K):
            x = int(next(it))
            y = int(next(it))
            asteroids.append((x, y))
        results.append(solve_case(K, N, M, P, Q, asteroids))
    sys.stdout.write("\n".join(map(str, results)) + "\n")


def read_your_input():
    # Helper function for AI
    import sys
    return sys.stdin.read()


if __name__ == "__main__":
    solve()