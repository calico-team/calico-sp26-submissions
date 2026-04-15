def solve(N, M, K, GRID):
    L = N + M - 1
    
    # Pre-allocate prefix sum array and structures to map points
    pref = [[0] * L for _ in range(L)]
    seats_by_u = {}
    
    unique_u_set = set()
    unique_v_set = set()
    
    # Calculate auras and populate the rotated grid space
    for r in range(N):
        row = GRID[r]
        blocked = [c for c in range(M) if row[c] == '#']
        n_blocked = len(blocked)
        blocked_idx = 0
        
        for c in range(M):
            if row[c] == '-':
                # Maintain the index of the first blocked seat to the right
                while blocked_idx < n_blocked and blocked[blocked_idx] < c:
                    blocked_idx += 1
                left_b = blocked_idx
                right_b = n_blocked - blocked_idx
                aura = min(left_b, right_b)
                
                # Transform to (u, v)
                u = r + c
                v = r - c + M - 1
                
                pref[u][v] = 1
                if u not in seats_by_u:
                    seats_by_u[u] = []
                seats_by_u[u].append((v, aura, r, c))
                unique_u_set.add(u)
                unique_v_set.add(v)
                
    # Build 2D prefix sum array to perform O(1) rectangle queries
    for i in range(L):
        for j in range(L):
            if i > 0:
                pref[i][j] += pref[i-1][j]
            if j > 0:
                pref[i][j] += pref[i][j-1]
            if i > 0 and j > 0:
                pref[i][j] -= pref[i-1][j-1]
                
    unique_u_list = sorted(list(unique_u_set))
    unique_v_list = sorted(list(unique_v_set))
    
    # Helper to check if a bounding box of size `d` contains >= K seats
    def check(d):
        for u1 in unique_u_list:
            u2 = min(u1 + d, L - 1)
            pu2 = pref[u2]
            pu1_1 = pref[u1-1] if u1 > 0 else None
            
            for v1 in unique_v_list:
                v2 = min(v1 + d, L - 1)
                
                # O(1) Rectangle sum
                ans = pu2[v2]
                if pu1_1: ans -= pu1_1[v2]
                if v1 > 0:
                    ans -= pu2[v1-1]
                    if pu1_1: ans += pu1_1[v1-1]
                
                if ans >= K:
                    return True
        return False

    # 1. Binary search for the minimal maximum distance (Main Objective)
    low = 0
    high = L - 1
    ans_D = high
    
    while low <= high:
        mid = (low + high) // 2
        if check(mid):
            ans_D = mid
            high = mid - 1
        else:
            low = mid + 1
            
    # 2. Extract the best K-seat subset minimizing aura loss (Bonus Objective)
    min_aura_sum = float('inf')
    best_seats = []
    
    for u1 in unique_u_list:
        u2 = min(u1 + ans_D, L - 1)
        pu2 = pref[u2]
        pu1_1 = pref[u1-1] if u1 > 0 else None
        
        for v1 in unique_v_list:
            v2 = min(v1 + ans_D, L - 1)
            
            ans = pu2[v2]
            if pu1_1: ans -= pu1_1[v2]
            if v1 > 0:
                ans -= pu2[v1-1]
                if pu1_1: ans += pu1_1[v1-1]
            
            # If this valid bounding box fits K or more seats, check aura loss
            if ans >= K:
                current_seats = []
                # Extract actual seats lying in the bounding box
                for u in range(u1, u2 + 1):
                    if u in seats_by_u:
                        for seat in seats_by_u[u]:
                            if v1 <= seat[0] <= v2:
                                current_seats.append(seat)
                
                # Sort by aura to take the K smallest auras
                current_seats.sort(key=lambda x: x[1])
                chosen = current_seats[:K]
                aura_sum = sum(x[1] for x in chosen)
                
                # Record the absolute best combination
                if aura_sum < min_aura_sum:
                    min_aura_sum = aura_sum
                    best_seats = [(x[2], x[3]) for x in chosen]
                    
    return best_seats


def main():
    import sys
    # Increase recursion depth for safety, load from stdin
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
            
    print('\n'.join(out))


if __name__ == '__main__':
    main()