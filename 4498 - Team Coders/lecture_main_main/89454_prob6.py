import sys
import heapq

def solve():
    # Read the number of test cases
    line = sys.stdin.readline()
    if not line or not line.strip():
        return
    try:
        T = int(line.strip())
    智except ValueError:
        return

    for _ in range(T):
        # Read N, M, K
        line = sys.stdin.readline()
        while line and not line.strip():
            line = sys.stdin.readline()
        if not line:
            break
        N, M, K = map(int, line.split())

        grid = [sys.stdin.readline().strip() for _ in range(N)]
        
        # Max dimension for the rotated grid
        L = N + M - 1
        pref = [[0] * (L + 2) for _ in range(L + 2)]
        seats = []
        
        # 1. Process grid: Calculate aura and transform to rotated (u, v) space
        for r in range(N):
            row = grid[r]
            # Find indices of all occupied seats in this row
            blocked = [c for c, char in enumerate(row) if char == '#']
            num_blocked = len(blocked)
            
            b_ptr = 0
            for c in range(M):
                if row[c] == '-':
                    # Find how many occupied seats are to the left
                    while b_ptr < num_blocked and blocked[b_ptr] < c:
                        b_ptr += 1
                    # Aura loss = min(occupied to left, occupied to right)
                    aura = min(b_ptr, num_blocked - b_ptr)
                    
                    # Rotated coordinates: Manhattan distance in (r,c) 
                    # becomes Chebyshev distance in (u,v)
                    u, v = r + c, r - c + M - 1
                    pref[u+1][v+1] = 1
                    seats.append({'u': u, 'v': v, 'aura': aura, 'r': r, 'c': c})
        
        # 2. Build 2D Prefix Sums for seat counting in O(1)
        for i in range(1, L + 1):
            for j in range(1, L + 1):
                pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]
        
        def get_count(u1, v1, u2, v2):
            u2, v2 = min(u2, L-1), min(v2, L-1)
            u1, v1 = max(u1, 0), max(v1, 0)
            if u1 > u2 or v1 > v2: return 0
            return pref[u2+1][v2+1] - pref[u1][v2+1] - pref[u2+1][v1] + pref[u1][v1]

        # 3. Binary search for the minimum possible maximum Manhattan distance (best_d)
        low, high = 0, L
        best_d = L
        unique_u = sorted(list(set(s['u'] for s in seats)))
        unique_v = sorted(list(set(s['v'] for s in seats)))

        while low <= high:
            mid = (low + high) // 2
            found = False
            for u1 in unique_u:
                # Early exit if there aren't enough seats in this u-range
                if get_count(u1, 0, u1 + mid, L - 1) < K: continue
                for v1 in unique_v:
                    if get_count(u1, v1, u1 + mid, v1 + mid) >= K:
                        found = True
                        break
                if found: break
            if found:
                best_d = mid
                high = mid - 1
            else:
                low = mid + 1
        
        # 4. Tie-breaker: Minimize total aura sum among boxes of size best_d
        min_total_aura = float('inf')
        final_coords = []
        
        # Group seats by u for faster retrieval
        seats_by_u = {}
        for s in seats:
            seats_by_u.setdefault(s['u'], []).append(s)

        for u1 in unique_u:
            if get_count(u1, 0, u1 + best_d, L - 1) < K: continue
            for v1 in unique_v:
                if get_count(u1, v1, u1 + best_d, v1 + best_d) >= K:
                    # Gather all seats within the current d-sized bounding box
                    candidates = []
                    for u_val in range(u1, min(u1 + best_d + 1, L)):
                        if u_val in seats_by_u:
                            for s in seats_by_u[u_val]:
                                if v1 <= s['v'] <= v1 + best_d:
                                    candidates.append(s)
                    
                    # Select K seats with the smallest aura loss
                    chosen = heapq.nsmallest(K, candidates, key=lambda x: x['aura'])
                    current_aura_sum = sum(x['aura'] for x in chosen)
                    
                    if current_aura_sum < min_total_aura:
                        min_total_aura = current_aura_sum
                        final_coords = [(x['r'], x['c']) for x in chosen]
                        if min_total_aura == 0: break
            if min_total_aura == 0: break

        # Output the K selected seat coordinates
        for r, c in final_coords:
            sys.stdout.write(f"{r} {c}\n")

if __name__ == "__main__":
    solve()