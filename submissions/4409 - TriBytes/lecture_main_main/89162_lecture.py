def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    seats = []
    
    # Precompute Aura Loss for each available seat
    for r in range(N):
        row = GRID[r]
        pref = [0] * M
        cnt = 0
        for c in range(M):
            pref[c] = cnt
            if row[c] == '#': cnt += 1
            
        suff = [0] * M
        cnt = 0
        for c in range(M - 1, -1, -1):
            suff[c] = cnt
            if row[c] == '#': cnt += 1
        
        for c in range(M):
            if row[c] == '-':
                aura = min(pref[c], suff[c])
                u = r + c
                v = r - c + M - 1
                seats.append((u, v, r, c, aura))
                
    if K == 0:
        return []

    # Coordinate mapping bounds
    U_max = N + M
    V_max = N + M
    
    # Build 2D Prefix Sum Array
    P = [[0] * V_max for _ in range(U_max)]
    points_by_v = [[] for _ in range(V_max)]
    
    unique_u = set()
    unique_v = set()
    
    for u, v, r, c, aura in seats:
        P[u][v] += 1
        points_by_v[v].append((u, v, r, c, aura))
        unique_u.add(u)
        unique_v.add(v)
        
    unique_u = sorted(list(unique_u))
    unique_v = sorted(list(unique_v))
    
    for v in unique_v:
        points_by_v[v].sort(key=lambda x: x[0])
        
    for i in range(U_max):
        for j in range(V_max):
            if i > 0: P[i][j] += P[i-1][j]
            if j > 0: P[i][j] += P[i][j-1]
            if i > 0 and j > 0: P[i][j] -= P[i-1][j-1]
            
    # Binary Search for minimum bounding box length D
    low = 0
    high = U_max + V_max
    best_D = high
    
    while low <= high:
        mid = (low + high) // 2
        possible = False
        for u0 in unique_u:
            u2 = min(u0 + mid, U_max - 1)
            for v0 in unique_v:
                v2 = min(v0 + mid, V_max - 1)
                
                # Check point capacity in O(1) time
                res = P[u2][v2]
                if u0 > 0: res -= P[u0-1][v2]
                if v0 > 0: res -= P[u2][v0-1]
                if u0 > 0 and v0 > 0: res += P[u0-1][v0-1]
                
                if res >= K:
                    possible = True
                    break
            if possible:
                break
                
        if possible:
            best_D = mid
            high = mid - 1
        else:
            low = mid + 1
            
    # Find the best window of size exactly `best_D` to minimize secondary objective (aura loss)
    D = best_D
    best_aura = float('inf')
    best_u_0 = -1
    best_v_0 = -1
    
    start_idx = [0] * V_max
    end_idx = [0] * V_max
    freq = [0] * 505  # Max aura is M/2, so 505 easily handles it
    
    for u0 in unique_u:
        active = []
        for v in unique_v:
            while start_idx[v] < len(points_by_v[v]) and points_by_v[v][start_idx[v]][0] < u0:
                start_idx[v] += 1
            while end_idx[v] < len(points_by_v[v]) and points_by_v[v][end_idx[v]][0] <= u0 + D:
                end_idx[v] += 1
            for idx in range(start_idx[v], end_idx[v]):
                active.append(points_by_v[v][idx])
                
        left = 0
        right = 0
        curr_points = 0
        curr_aura_sum = 0
        
        # Dynamic sliding window inside active elements
        while left < len(active):
            while right < len(active) and active[right][1] <= active[left][1] + D:
                a = active[right][4]
                freq[a] += 1
                curr_points += 1
                curr_aura_sum += a
                right += 1
                
            if curr_points >= K:
                to_drop = curr_points - K
                dropped_sum = 0
                for a in range(500, -1, -1):
                    if to_drop == 0: break
                    if freq[a] > 0:
                        take = min(freq[a], to_drop)
                        dropped_sum += take * a
                        to_drop -= take
                
                sum_K = curr_aura_sum - dropped_sum
                if sum_K < best_aura:
                    best_aura = sum_K
                    best_u_0 = u0
                    best_v_0 = active[left][1]
                    
            a = active[left][4]
            freq[a] -= 1
            curr_points -= 1
            curr_aura_sum -= a
            left += 1
            
    # Reconstruct and extract the exact K coordinates forming the optimal set
    best_pts = []
    for v in unique_v:
        if best_v_0 <= v <= best_v_0 + D:
            for p in points_by_v[v]:
                if best_u_0 <= p[0] <= best_u_0 + D:
                    best_pts.append(p)
                    
    best_pts.sort(key=lambda x: x[4])
    
    return [(best_pts[i][2], best_pts[i][3]) for i in range(K)]


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    if not data:
        return
        
    T = int(data[0])
    idx = 1
    out = []
    
    for _ in range(T):
        N = int(data[idx])
        M = int(data[idx+1])
        K = int(data[idx+2])
        idx += 3
        
        GRID = []
        for _ in range(N):
            GRID.append(data[idx])
            idx += 1
            
        result = solve(N, M, K, GRID)
        for r, c in result:
            out.append(f"{r} {c}")
            
    if out:
        print("\n".join(out))

if __name__ == '__main__':
    main()