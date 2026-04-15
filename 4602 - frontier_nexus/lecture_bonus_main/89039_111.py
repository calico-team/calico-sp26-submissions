import sys
import bisect

def solve():
    # Read all tokens from standard input for fast I/O
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
            
        seats = []
        
        # Parse grid, calculate aura loss, and transform to Chebyshev coordinates
        for r in range(N):
            row_str = grid[r]
            total_hash = row_str.count('#')
            left_hash = 0
            for c in range(M):
                if row_str[c] == '#':
                    left_hash += 1
                else:
                    right_hash = total_hash - left_hash
                    aura = left_hash if left_hash < right_hash else right_hash
                    
                    u = r + c
                    v = r - c + M - 1
                    seats.append((u, v, aura, r, c))
                    
        S = N + M - 1
        
        # 1D array mapped to 2D Prefix Sum for faster memory access
        pref = [0] * ((S + 1) * (S + 1))
        
        for u, v, aura, r, c in seats:
            pref[(u + 1) * (S + 1) + (v + 1)] += 1
            
        for i in range(1, S + 1):
            row_offset = i * (S + 1)
            prev_offset = (i - 1) * (S + 1)
            for j in range(1, S + 1):
                pref[row_offset + j] += (pref[prev_offset + j] + 
                                         pref[row_offset + j - 1] - 
                                         pref[prev_offset + j - 1])
                                         
        def get_count(u1, v1, u2, v2):
            if u2 >= S: u2 = S - 1
            if v2 >= S: v2 = S - 1
            u1_offset = u1 * (S + 1)
            u21_offset = (u2 + 1) * (S + 1)
            return (pref[u21_offset + v2 + 1] - 
                    pref[u1_offset + v2 + 1] - 
                    pref[u21_offset + v1] + 
                    pref[u1_offset + v1])

        # Binary search for the minimum maximum Manhattan distance (L)
        low = 0
        high = S - 1
        ans_L = high
        
        while low <= high:
            mid = (low + high) // 2
            found = False
            for i in range(S - mid):
                # Optimization: Skip if the entire u-band doesn't contain K seats
                if get_count(i, 0, i + mid, S - 1) < K:
                    continue
                for j in range(S - mid):
                    if get_count(i, j, i + mid, j + mid) >= K:
                        found = True
                        break
                if found:
                    break
            
            if found:
                ans_L = mid
                high = mid - 1
            else:
                low = mid + 1
                
        # Find the subset of K elements with minimum aura within ANY valid L x L box
        best_cost = float('inf')
        best_seats = []
        
        # Sort seats by u-coordinate to quickly extract slices
        seats.sort(key=lambda x: x[0])
        u_vals = [s[0] for s in seats]
        
        # Only iterate over actual u-coordinates to anchor the sliding window
        u_anchors = sorted(list(set(u_vals)))
        
        for u_start in u_anchors:
            u_end = u_start + ans_L
            
            if get_count(u_start, 0, u_end, S - 1) < K:
                continue
                
            left_idx = bisect.bisect_left(u_vals, u_start)
            right_idx = bisect.bisect_right(u_vals, u_end)
            
            slice_pts = seats[left_idx:right_idx]
            slice_pts.sort(key=lambda x: x[1]) # Sort the local slice by v-coordinate
            
            n_slice = len(slice_pts)
            right = 0
            
            # Sliding window over v-coordinates to find maximal valid sets
            for left in range(n_slice):
                while right < n_slice and slice_pts[right][1] - slice_pts[left][1] <= ans_L:
                    right += 1
                
                if right - left >= K:
                    cand = slice_pts[left:right]
                    cand.sort(key=lambda x: x[2]) # Sort the valid window by aura
                    
                    cost = sum(pt[2] for pt in cand[:K])
                    if cost < best_cost:
                        best_cost = cost
                        best_seats = cand[:K]
                        
        for pt in best_seats:
            out.append(f"{pt[3]} {pt[4]}")
            
    print('\n'.join(out))

if __name__ == '__main__':
    solve()