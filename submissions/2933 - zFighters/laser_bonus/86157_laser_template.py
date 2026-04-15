def solve(K, N, M, P, Q, X, Y):
    """
    Find the index of the first asteroid hit by the laser.
    
    K: Number of asteroids
    N, M: Bounds for x- and y-coordinates
    P, Q: Laser movement (P along y-axis, Q along x-axis)
    X: List of x-coordinates of asteroids
    Y: List of y-coordinates of asteroids
    """
    def gcd(a, b):
        old_r, r = a, b
        old_s, s = 1, 0
        while r != 0:
            quo = old_r // r
            old_r, r = r, old_r - quo * r
            old_s, s = s, old_s - quo * s
        return old_r, old_s

    def l_c(a, b, m):
        g, x = gcd(a, m)
        if b % g != 0:
            return None
        m_new = m // g
        x0 = ((b // g) * x) % m_new
        return x0, m_new

    def remander(r1, m1, r2, m2):
        res = l_c(m1, r2 - r1, m2)
        if res is None:
            return None
        k0, m_k = res
        new_m = m1 * m_k
        new_r = (r1 + k0 * m1) % new_m
        return new_r, new_m

    start_x, start_y = X[0], Y[0]
    min_step = float('inf')
    index = -1

    for i in range(K):
        dx = (X[i] - start_x) % N
        dy = (Y[i] - start_y) % M
        
        sol_x = l_c(Q, dx, N)
        if sol_x is None: continue
        
        sol_y = l_c(P, dy, M)
        if sol_y is None: continue
        
        final = remander(sol_x[0], sol_x[1], sol_y[0], sol_y[1])
        if final is None: continue
        
        s, period = final
        if s == 0:
            s = period
            
        if s < min_step:
            min_step = s
            index = i

    return index

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