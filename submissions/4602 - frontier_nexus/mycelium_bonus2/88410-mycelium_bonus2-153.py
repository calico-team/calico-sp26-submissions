import sys

def sum_linear_floor(A, B, C, L, R):
    """
    Computes sum_{x=L}^{R} max(0, floor((A - B*x) / C))
    A simple O(N) sweep-line replacing grid simulation.
    """
    if L > R: return 0
    ans = 0
    for x in range(L, R + 1):
        val = (A - B * x) // C
        if val > 0:
            ans += val
    return ans

def count_Q4(dx, dy, D, X_free):
    """
    Counts tiles in Q4: x >= 0, y' > 0 (where y' = -y)
    Evaluates Grass detour boundaries linearly.
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
    Evaluates the upper bounds when Grass paths from two different 
    flanks converge in the "shadow" quadrant.
    """
    if L > R: return 0
    ans = 0
    for x in range(L, R + 1):
        f1 = (A1 - B1 * x) // C1
        f2 = (A2 - B2 * x) // C2
        
        # Mycelium must beat both Grass wave fronts
        val = min(f1, f2)
        if val > 0:
            ans += val
    return ans

def solve():
    # Read all tokens from standard input
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
        
        # Max coordinate offsets Mycelium can expand unhindered along the axes
        X_free = (2 * D - 1) // 9 + 1
        Y_free = (2 * D - 1) // 9 + 1
        X_neg_free = (2 * D - 1) // 5 + 1
        Y_neg_free = (2 * D - 1) // 5 + 1
        
        # Q1: The quadrant facing the Grass directly
        R1 = (2 * D - 1) // 9
        q1_count = 0
        if R1 >= 0:
            q1_count = (R1 + 1) * (R1 + 2) // 2
            
        # Q4: Perpendicular quadrant 1
        q4_count = count_Q4(dx, dy, D, X_free)
        
        # Q2: Perpendicular quadrant 2 (symmetric to Q4)
        q2_count = count_Q4(dy, dx, D, Y_free)
        
        # Q3: The "shadow" quadrant directly opposite Grass
        C1 = 2 * max(0, X_free - dx)
        C2 = 2 * max(0, Y_free - dy)
        X_crit = (2 * D + 2 * C1 - 1 - 5 * Y_neg_free) // 5
        
        # Calculate critical boundary points where the piecewise functions shift
        pts = [1, max(1, X_neg_free + 1), max(1, X_crit + 1), D + 1]
        pts = sorted(list(set(p for p in pts if p <= D + 1)))
        
        q3_count = 0
        for i in range(len(pts) - 1):
            L = pts[i]
            R = pts[i+1] - 1
            if L <= R:
                # Set up F1 function pieces
                if L <= X_crit:
                    A1, B1, C1_val = 2 * D + 2 * C1 - 1, 5, 5
                else:
                    A1, B1, C1_val = 2 * D + 2 * C1 + 4 * Y_neg_free - 1, 5, 9
                
                # Set up F2 function pieces
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