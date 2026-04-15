import sys

def solve():
    # Read all input from standard input
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
            
        # 1. Precalculate Aura Loss for all seats
        aura = [[0] * M for _ in range(N)]
        for r in range(N):
            occ_left = 0
            for c in range(M):
                if grid[r][c] == '#':
                    occ_left += 1
                else:
                    aura[r][c] = occ_left
                    
            occ_right = 0
            for c in range(M - 1, -1, -1):
                if grid[r][c] == '#':
                    occ_right += 1
                else:
                    aura[r][c] = min(aura[r][c], occ_right)
        
        # 2. Extract available seats and map to Chebyshev (u, v) coordinates
        points = []
        MAX_DIM = N + M
        for r in range(N):
            for c in range(M):
                if grid[r][c] == '-':
                    u = r + c
                    v = r - c + M - 1  # Offset to keep indices positive
                    points.append((u, v, r, c, aura[r][c]))
                    
        # 3. Build 2D Prefix Sum array for O(1) range queries
        pref = [[0] * (MAX_DIM + 1) for _ in range(MAX_DIM + 1)]
        for p in points:
            pref[p[0] + 1][p[1] + 1] += 1
            
        for i in range(MAX_DIM):
            for j in range(MAX_DIM):
                pref[i+1][j+1] += pref[i][j+1] + pref[i+1][j] - pref[i][j]
                
        def count_pts(u1, v1, u2, v2):
            u1 = max(0, u1)
            v1 = max(0, v1)
            u2 = min(MAX_DIM - 1, u2)
            v2 = min(MAX_DIM - 1, v2)
            if u1 > u2 or v1 > v2: 
                return 0
            return pref[u2+1][v2+1] - pref[u1][v2+1] - pref[u2+1][v1] + pref[u1][v1]

        def check(D):
            for i in range(MAX_DIM - D):
                for j in range(MAX_DIM - D):
                    if count_pts(i, j, i + D, j + D) >= K:
                        return True
            return False

        # 4. Binary search for the minimum max-Manhattan distance
        low = 0
        high = MAX_DIM
        best_D = high
        
        while low <= high:
            mid = (low + high) // 2
            if check(mid):
                best_D = mid
                high = mid - 1
            else:
                low = mid + 1
                
        # 5. Find the specific K seats that minimize Aura Loss
        points_by_u = [[] for _ in range(MAX_DIM)]
        for p in points:
            points_by_u[p[0]].append(p)
            
        best_aura_sum = float('inf')
        best_seats = []
        
        for i in range(MAX_DIM - best_D):
            valid_js = []
            for j in range(MAX_DIM - best_D):
                if count_pts(i, j, i + best_D, j + best_D) >= K:
                    valid_js.append(j)
            
            if not valid_js:
                continue
                
            # Gather points in the current u-range
            pts = []
            for u in range(i, i + best_D + 1):
                pts.extend(points_by_u[u])
            
            # Sort by v-coordinate for fast window filtering
            pts.sort(key=lambda p: p[1]) 
            
            for j in valid_js:
                # Filter points inside the exact DxD box
                in_box = [p for p in pts if j <= p[1] <= j + best_D]
                # Sort greedily by Aura Loss
                in_box.sort(key=lambda p: p[4]) 
                
                if len(in_box) >= K:
                    current_aura_sum = sum(p[4] for p in in_box[:K])
                    if current_aura_sum < best_aura_sum:
                        best_aura_sum = current_aura_sum
                        best_seats = in_box[:K]

        # 6. Format coordinates
        for p in best_seats:
            out.append(f"{p[2]} {p[3]}")
            
    print('\n'.join(out))

if __name__ == '__main__':
    solve()