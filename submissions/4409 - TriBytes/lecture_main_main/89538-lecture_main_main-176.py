import sys

def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    seats = []
    U_max = N + M - 1
    V_max = N + M - 1
    
    pref = [[0] * (V_max + 1) for _ in range(U_max + 1)]
    pref_aura = [[0] * (V_max + 1) for _ in range(U_max + 1)]
    
    seats_by_u = [[] for _ in range(U_max)]
    
    # 1. Parse Grid and Calculate Aura losses
    for r in range(N):
        row = GRID[r]
        total_hashes = row.count('#')
        left_hashes = 0
        for c in range(M):
            if row[c] == '#':
                left_hashes += 1
            else:
                right_hashes = total_hashes - left_hashes
                aura = min(left_hashes, right_hashes)
                
                # Transform coordinates
                u = r + c
                v = r - c + M - 1
                
                seat_info = (u, v, r, c, aura)
                seats.append(seat_info)
                seats_by_u[u].append(seat_info)
                
                pref[u+1][v+1] += 1
                pref_aura[u+1][v+1] += aura
                
    if K == 1:
        best_seat = min(seats, key=lambda x: x[4])
        return [(best_seat[2], best_seat[3])]
        
    # 2. Build 2D Prefix Sums
    for i in range(1, U_max + 1):
        for j in range(1, V_max + 1):
            pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]
            pref_aura[i][j] += pref_aura[i-1][j] + pref_aura[i][j-1] - pref_aura[i-1][j-1]
            
    def get_count(u1, v1, u2, v2):
        if u1 > u2 or v1 > v2: return 0
        return pref[u2+1][v2+1] - pref[u1][v2+1] - pref[u2+1][v1] + pref[u1][v1]

    def get_aura_sum(u1, v1, u2, v2):
        if u1 > u2 or v1 > v2: return 0
        return pref_aura[u2+1][v2+1] - pref_aura[u1][v2+1] - pref_aura[u2+1][v1] + pref_aura[u1][v1]

    # Pre-filter axes to avoid checking totally empty regions
    valid_u1 = [u for u in range(U_max) if get_count(u, 0, u, V_max - 1) > 0]
    valid_v1 = [v for v in range(V_max) if get_count(0, v, U_max - 1, v) > 0]
    
    def check(D):
        """Returns True if there's any DxD window with >= K seats"""
        for u1 in valid_u1:
            u2 = min(U_max - 1, u1 + D)
            pu2 = pref[u2+1]
            pu1 = pref[u1]
            for v1 in valid_v1:
                v2 = min(V_max - 1, v1 + D)
                if pu2[v2+1] - pu1[v2+1] - pu2[v1] + pu1[v1] >= K:
                    return True
        return False
        
    # 3. Binary Search for the Minimum Maximum Manhattan Distance
    low = 0
    high = max(U_max, V_max)
    D_min = high
    while low <= high:
        mid = (low + high) // 2
        if check(mid):
            D_min = mid
            high = mid - 1
        else:
            low = mid + 1
            
    # 4. Find the set among optimal windows that minimizes total Aura Loss
    best_aura_sum = float('inf')
    best_points = []
    
    for u1 in valid_u1:
        u2 = min(U_max - 1, u1 + D_min)
        for v1 in valid_v1:
            v2 = min(V_max - 1, v1 + D_min)
            
            count = get_count(u1, v1, u2, v2)
            if count >= K:
                # Ensure it's a tight canonical bounding box mapping to a subset
                if get_count(u1, v1, u1, v2) > 0 and get_count(u1, v1, u2, v1) > 0:
                    
                    if count == K:
                        aura_sum = get_aura_sum(u1, v1, u2, v2)
                        if aura_sum < best_aura_sum:
                            best_aura_sum = aura_sum
                            best_points = (u1, v1, u2, v2, True, None)
                    else:
                        # Window contains M > K seats. We must collect and sort them.
                        pts = []
                        for u in range(u1, u2 + 1):
                            for s in seats_by_u[u]:
                                if v1 <= s[1] <= v2:
                                    pts.append(s)
                                    
                        pts.sort(key=lambda x: x[4])  # Greedily pick the ones with smallest aura
                        current_aura_sum = sum(p[4] for p in pts[:K])
                        
                        if current_aura_sum < best_aura_sum:
                            best_aura_sum = current_aura_sum
                            best_points = (u1, v1, u2, v2, False, pts[:K])
                            
    # Final extraction step
    if best_points[4]: # True implies the entire window perfectly matched K points
        u1, v1, u2, v2 = best_points[0], best_points[1], best_points[2], best_points[3]
        final_pts = []
        for u in range(u1, u2 + 1):
            for s in seats_by_u[u]:
                if v1 <= s[1] <= v2:
                    final_pts.append(s)
    else: # False means we already saved the explicit best slice
        final_pts = best_points[5]
        
    return [(pt[2], pt[3]) for pt in final_pts[:K]]


def main():
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
        
        GRID = []
        for _ in range(N):
            GRID.append(input_data[idx])
            idx += 1
            
        result = solve(N, M, K, GRID)
        for r, c in result:
            out.append(f"{r} {c}")
            
    print('\n'.join(out))


if __name__ == '__main__':
    main()