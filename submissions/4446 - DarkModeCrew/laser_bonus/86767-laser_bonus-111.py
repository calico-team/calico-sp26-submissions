def func_for_gcd(a, b):
    while b:
        a, b = b, a % b
    return a
    
def extended_gcd_func(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = extended_gcd_func(b, a % b)
    x = y1
    y = x1 - y1 * (a // b)
    return g, x, y

def inverse_of_mod_func(a, m):
    g, x, y = extended_gcd_func(a, m)
    if g != 1:
        return -1 
    return (x % m + m) % m

def solve(K, N, M, P, Q, x, y):
    min_t = float('inf')
    hit_index = -1
    initial_x = x[0]
    initial_y = y[0]
    
    for i in range(K):
        dx = (x[i] - initial_x) % N
        dy = (y[i] - initial_y) % M
        
        gx = func_for_gcd(Q, N) 
        if dx % gx != 0:
            continue
        
        Q_prime = Q // gx
        N_prime = N // gx
        dx_prime = dx // gx
        
        inv_Q = inverse_of_mod_func(Q_prime, N_prime) 
        A = (dx_prime * inv_Q) % N_prime
        M1 = N_prime
        
        gy = func_for_gcd(P, M) 
        if dy % gy != 0:
            continue
        
        P_prime = P // gy
        M_prime = M // gy
        dy_prime = dy // gy
        
        inv_P = inverse_of_mod_func(P_prime, M_prime) 
        B = (dy_prime * inv_P) % M_prime
        M2 = M_prime
        
        g, u, v = extended_gcd_func(M1, M2) 
        if (B - A) % g != 0:
            continue
        L = (M1 // g) * M2 
        
        diff = (B - A) // g
        multiplier = (diff * u) % (M2 // g)
        
        t = A + M1 * multiplier
        t = (t % L + L) % L
        
        if t == 0:
            t = L
            
        if t < min_t:
            min_t = t
            hit_index = i 
            
    return hit_index

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
            a_i = int(coords[0])
            b_i = int(coords[1])
            X.append(a_i)
            Y.append(b_i)

        print(solve(K, N, M, P, Q, X, Y))

if __name__ == '__main__':
    main()