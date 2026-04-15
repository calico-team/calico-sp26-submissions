import sys
from collections import deque

class Point:
    __slots__ = ['r', 'c', 'u', 'v', 'aura']
    def __init__(self, r, c, u, v, aura):
        self.r = r
        self.c = c
        self.u = u
        self.v = v
        self.aura = aura

def solve():
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
            
        points = []
        points_by_u = [[] for _ in range(N + M + 2)]
        
        # Calculate aura losses and apply coordinate transformation
        for r in range(N):
            row = grid[r]
            left_hash = [0] * M
            right_hash = [0] * M
            
            cnt = 0
            for c in range(M):
                left_hash[c] = cnt
                if row[c] == '#':
                    cnt += 1
            
            cnt = 0
            for c in range(M - 1, -1, -1):
                right_hash[c] = cnt
                if row[c] == '#':
                    cnt += 1
                    
            for c in range(M):
                if row[c] == '-':
                    aura = min(left_hash[c], right_hash[c])
                    u = r + c + 1
                    v = r - c + M
                    p = Point(r, c, u, v, aura)
                    points.append(p)
                    points_by_u[u].append(p)
        
        U_max = N + M - 1
        V_max = N + M - 1
        V_stride = V_max + 2
        
        # 1D array representing 2D Prefix Sums for performance
        pref = [0] * ((U_max + 2) * V_stride)
        for p in points:
            pref[p.u * V_stride + p.v] += 1
            
        for i in range(1, U_max + 2):
            curr_idx = i * V_stride
            prev_idx = (i - 1) * V_stride
            for j in range(1, V_max + 2):
                pref[curr_idx + j] = pref[curr_idx + j] + pref[prev_idx + j] + pref[curr_idx + j - 1] - pref[prev_idx + j - 1]
                
        def get_count(u1, v1, u2, v2):
            if u2 > U_max: u2 = U_max
            if v2 > V_max: v2 = V_max
            idx1 = (u1 - 1) * V_stride
            idx2 = u2 * V_stride
            return pref[idx2 + v2] - pref[idx1 + v2] - pref[idx2 + v1 - 1] + pref[idx1 + v1 - 1]

        # Binary search for the minimum max Manhattan distance D*
        low = 0
        high = U_max + V_max
        D_star = high
        
        while low <= high:
            mid = (low + high) // 2
            valid = False
            for u in range(1, U_max + 1):
                for v in range(1, V_max + 1):
                    if get_count(u, v, u + mid, v + mid) >= K:
                        valid = True
                        break
                if valid:
                    break
            
            if valid:
                D_star = mid
                high = mid - 1
            else:
                low = mid + 1

        # Locate all windows of size D* x D* that bound at least K elements
        valid_corners_by_u = [[] for _ in range(U_max + 1)]
        for u in range(1, U_max + 1):
            for v in range(1, V_max + 1):
                if get_count(u, v, u + D_star, v + D_star) >= K:
                    valid_corners_by_u[u].append(v)
                    
        active_pts = [deque() for _ in range(V_max + 2)]
        
        # Initialize Sweep Line
        for u in range(1, min(D_star + 1, U_max + 1)):
            for p in points_by_u[u]:
                active_pts[p.v].append(p)
                
        min_aura = float('inf')
        best_pts = []
        
        for u in range(1, U_max + 1):
            if u + D_star <= U_max:
                for p in points_by_u[u + D_star]:
                    active_pts[p.v].append(p)
                    
            for v in valid_corners_by_u[u]:
                cand = []
                end_v = min(v + D_star, V_max)
                for curr_v in range(v, end_v + 1):
                    if active_pts[curr_v]:
                        cand.extend(active_pts[curr_v])
                
                # Resolving Tiebreakers minimizing Aura loss
                if len(cand) == K:
                    aura_sum = sum(p.aura for p in cand)
                    if aura_sum < min_aura:
                        min_aura = aura_sum
                        best_pts = cand[:]
                elif len(cand) > K:
                    cand.sort(key=lambda p: (p.aura, p.r, p.c))
                    topK = cand[:K]
                    aura_sum = sum(p.aura for p in topK)
                    if aura_sum < min_aura:
                        min_aura = aura_sum
                        best_pts = topK
                        
            # Evict bounds that drop outside the sweep-line criteria
            for p in points_by_u[u]:
                active_pts[p.v].popleft()
                
        for p in best_pts:
            out.append(f"{p.r} {p.c}")
            
    print("\n".join(out))

if __name__ == '__main__':
    solve()