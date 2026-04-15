import sys
from bisect import bisect_left, bisect_right

def solve():
    # Read all tokens from standard input
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    idx = 1
    
    out = []
    
    for _ in range(T):
        N = int(input_data[idx])
        M = int(input_data[idx+1])
        K = int(input_data[idx+2])
        idx += 3
        
        grid = []
        for _ in range(N):
            grid.append(input_data[idx])
            idx += 1
        
        all_seats = []
        
        # Parse grid and calculate aura loss
        for r in range(N):
            row_str = grid[r]
            total_hash = row_str.count('#')
            left_hash = 0
            for c in range(M):
                if row_str[c] == '#':
                    left_hash += 1
                else:
                    right_hash = total_hash - left_hash
                    # Aura loss is the minimum of people blocking the left or right
                    aura = left_hash if left_hash < right_hash else right_hash
                    
                    # Rotated coordinates for Chebyshev distance
                    u = r + c
                    v = r - c + M - 1
                    
                    # Store as (r, c, u, v, aura)
                    all_seats.append((r, c, u, v, aura))
        
        S = N + M - 1
        
        # Build 2D prefix sum array for the rotated grid
        pref = [[0] * (S + 1) for _ in range(S + 1)]
        for pt in all_seats:
            pref[pt[2] + 1][pt[3] + 1] += 1
            
        for i in range(1, S + 1):
            row = pref[i]
            prev_row = pref[i-1]
            for j in range(1, S + 1):
                row[j] += prev_row[j] + row[j-1] - prev_row[j-1]
        
        def check(L):
            max_i = S - L if S - L > 0 else 1
            for i in range(max_i):
                u2 = i + L if i + L < S else S - 1
                # Optimization: Skip if the entire u-band doesn't contain K seats
                if pref[u2+1][S] - pref[i][S] < K:
                    continue
                for j in range(max_i):
                    v2 = j + L if j + L < S else S - 1
                    # 2D Range Sum Query
                    if pref[u2+1][v2+1] - pref[i][v2+1] - pref[u2+1][j] + pref[i][j] >= K:
                        return True
            return False
        
        # Binary search for the minimum maximum Manhattan distance (L)
        low = 0
        high = S - 1
        ans = high
        while low <= high:
            mid = (low + high) // 2
            if check(mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        L_opt = ans
        
        # Find all valid u-coordinate bands that contain >= K seats within L_opt 
        valid_u = []
        max_i = S - L_opt if S - L_opt > 0 else 1
        for i in range(max_i):
            u2 = i + L_opt if i + L_opt < S else S - 1
            if pref[u2+1][S] - pref[i][S] < K:
                continue
            for j in range(max_i):
                v2 = j + L_opt if j + L_opt < S else S - 1
                if pref[u2+1][v2+1] - pref[i][v2+1] - pref[u2+1][j] + pref[i][j] >= K:
                    valid_u.append(i)
                    break
        
        # Sort available seats by their u-coordinate for rapid slicing
        all_seats.sort(key=lambda x: x[2])
        u_vals = [pt[2] for pt in all_seats]
        
        best_cost = float('inf')
        best_seats = []
        
        # Extract candidates to minimize aura loss
        for i in valid_u:
            u2 = i + L_opt if i + L_opt < S else S - 1
            
            left_idx = bisect_left(u_vals, i)
            right_idx = bisect_right(u_vals, u2)
            
            slice_pts = all_seats[left_idx:right_idx]
            slice_pts.sort(key=lambda x: x[3]) # Sort the local u-band by v-coordinate
            
            right = 0
            n_slice = len(slice_pts)
            last_right = -1
            
            # Sliding window over v-coordinates to find maximal valid sets
            for left in range(n_slice):
                while right < n_slice and slice_pts[right][3] - slice_pts[left][3] <= L_opt:
                    right += 1
                
                # Only check if the window expanded to avoid evaluating strict subsets
                if right > last_right:
                    if right - left >= K:
                        candidate_pts = slice_pts[left:right]
                        # Sort by aura to satisfy the bonus constraint
                        candidate_pts.sort(key=lambda x: x[4]) 
                        cost = sum(pt[4] for pt in candidate_pts[:K])
                        
                        if cost < best_cost:
                            best_cost = cost
                            best_seats = candidate_pts[:K]
                    last_right = right
                    
        for pt in best_seats:
            out.append(f"{pt[0]} {pt[1]}")

    print('\n'.join(out))

if __name__ == '__main__':
    solve()