from math import gcd

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x, y = extended_gcd(b, a % b)
    return g, y, x - (a // b) * y

def solve_linear_congruence(a, b, m):
    """Solve a*t ≡ b (mod m), returns (t0, step) or None"""
    g = gcd(a, m)
    if b % g != 0:
        return None
    a_, b_, m_ = a // g, b % m // g, m // g
    _, inv, _ = extended_gcd(a_, m_)
    t0 = (b_ * inv) % m_
    return t0, m_

def crt(r1, m1, r2, m2):
    """Combine t ≡ r1 (mod m1) and t ≡ r2 (mod m2)"""
    g, p, q = extended_gcd(m1, m2)
    if (r2 - r1) % g != 0:
        return None
    lcm = m1 * m2 // g
    t0 = (r1 + m1 * ((r2 - r1) // g * p % (m2 // g))) % lcm
    return t0, lcm

def solve(K, N, M, P, Q, X, Y):
    x0, y0 = X[0], Y[0]
    
    best_t = None
    best_i = -1
    
    for i in range(K):
        dx = (X[i] - x0) % N
        dy = (Y[i] - y0) % M
        
        sol_x = solve_linear_congruence(Q, dx, N)
        if sol_x is None:
            continue
        tx, step_x = sol_x
        
        sol_y = solve_linear_congruence(P, dy, M)
        if sol_y is None:
            continue
        ty, step_y = sol_y
        
        combined = crt(tx, step_x, ty, step_y)
        if combined is None:
            continue
        
        t, period = combined
        
        if t == 0:
            t = period  
        if i == 0 and t == period:
            pass
        
        if best_t is None or t < best_t:
            best_t = t
            best_i = i
    
    return best_i

def main():
    T = int(input())
    for _ in range(T):
        line = input().split()
        K = int(line[0])
        N = int(line[1])
        M = int(line[2])
        P = int(line[3])
        Q = int(line[4])
        
        X = []
        Y = []
        for _ in range(K):
            coords = input().split()
            X.append(int(coords[0]))
            Y.append(int(coords[1]))
        
        print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
    main()