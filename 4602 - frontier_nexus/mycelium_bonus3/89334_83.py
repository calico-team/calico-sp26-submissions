import sys

def floor_sum(n, m, a, b):
    """
    Computes sum_{i=0}^{n-1} floor((a * i + b) / m) in O(log m)
    This is the engine that bypasses the O(D) loop.
    """
    ans = 0
    while True:
        if a >= m:
            ans += n * (n - 1) // 2 * (a // m)
            a %= m
        if b >= m:
            ans += n * (b // m)
            b %= m
        y_max = (a * n + b) // m
        if y_max == 0:
            break
        b = (a * n + b) % m
        n, m, a = y_max, a, m
    return ans

def sum_linear_floor(A, B, C, L, R):
    """
    Computes sum_{x=L}^{R} max(0, floor((A - B*x) / C))
    Adapts our specific inequalities for the floor_sum function.
    """
    if L > R: 
        return 0
    R_prime = min(R, (A - C) // B)
    if L > R_prime: 
        return 0
    
    A_prime = A - B * L
    N = R_prime - L + 1
    A_double_prime = A_prime - B * (N - 1)
    
    return floor_sum(N, C, B, A_double_prime)

def count_Q4(dx, dy, D, X_free):
    """
    Counts tiles in the perpendicular quadrant using floor_sum.
    """
    ans = 0
    if dx >= X_free:
        ans += sum_linear_floor(2 * dx + 2 * dy - 1, 9, 5, 0, dx)
        ans += sum_linear_floor(-2 * dx + 2 * dy - 1, 5, 5, dx + 1, D)
    else:
        ans += sum_linear_floor(4 * X_free - 2 * dx + 2 * dy - 1, 9, 5, 0, X_free)
        ans += sum_linear_floor(-2 * dx + 2 * dy - 1, 5, 5, X_free + 1, D)
    return ans

def solve_interval(L, R, A1, B1, C1, A2, B2, C2):
    """
    Finds the exact crossover point of the two Grass wavefronts using 
    binary search, then uses floor_sum on each half.
    """
    if L > R: return 0
    low, high = L, R
    M = L - 1
    
    # O(log D) binary search for the crossover point where F1(x) >= F2(x)
    while low <= high:
        mid = (low + high) // 2
        f1 = (A1 - B1 * mid) // C1
        f2 = (A2 - B2 * mid) // C2
        if f1 < f2:
            M = mid
            low = mid + 1
        else:
            high = mid - 1
            
    ans = 0
    ans += sum_linear_floor(A1, B1, C1, L, M)
    ans += sum_linear_floor(A2, B2, C2, M + 1, R)
    return ans

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    idx = 1
    
    out = []
    for _ in range(T):
        xG = int(input_data[idx])
        yG = int(input_data[idx+1])
        xM = int(input_data[idx+2])
        yM = int(input_data[idx+3])
        idx += 4
        
        dx = abs(xG - xM)
        dy = abs(yG - yM)
        D = dx + dy
        
        X_free = (2 * D - 1) // 9 + 1
        Y_free = (2 * D - 1) // 9 + 1
        X_neg_free = (2 * D - 1) // 5 + 1
        Y_neg_free = (2 * D - 1) // 5 + 1
        
        # Q1
        R1 = (2 * D - 1) // 9
        q1_count = 0
        if R1 >= 0:
            q1_count = (R1 + 1) * (R1 + 2) // 2
            
        # Q4
        q4_count = count_Q4(dx, dy, D, X_free)
        
        # Q2
        q2_count = count_Q4(dy, dx, D, Y_free)
        
        # Q3: The complex "shadow" quadrant
        C1 = 2 * max(0, X_free - dx)
        C2 = 2 * max(0, Y_free - dy)
        X_crit = (2 * D + 2 * C1 - 1 - 5 * Y_neg_free) // 5
        
        pts = [1, max(1, X_neg_free + 1), max(1, X_crit + 1), D + 1]
        pts = sorted(list(set(p for p in pts if p <= D + 1)))
        
        q3_count = 0
        for i in range(len(pts) - 1):
            L = pts[i]
            R = pts[i+1] - 1
            if L <= R:
                if L <= X_crit:
                    A1, B1, C1_val = 2 * D + 2 * C1 - 1, 5, 5
                else:
                    A1, B1, C1_val = 2 * D + 2 * C1 + 4 * Y_neg_free - 1, 5, 9
                
                if L <= X_neg_free:
                    A2, B2, C2_val = 2 * D + 2 * C2 + 4 * X_neg_free - 1, 9, 5
                else:
                    A2, B2, C2_val = 2 * D + 2 * C2 - 1, 5, 5
                    
                q3_count += solve_interval(L, R, A1, B1, C1_val, A2, B2, C2_val)
                
        total_mycelium = q1_count + q2_count + q3_count + q4_count
        out.append(str(total_mycelium))
        
    print('\n'.join(out))

if __name__ == '__main__':
    solve()