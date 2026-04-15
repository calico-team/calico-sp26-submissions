import sys
from bisect import bisect_left, bisect_right

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
        for r in range(N):
            row = grid[r]
            left_counts = [0] * M
            curr = 0
            for c in range(M):
                left_counts[c] = curr
                if row[c] == '#':
                    curr += 1
            
            right_counts = [0] * M
            curr = 0
            for c in range(M - 1, -1, -1):
                right_counts[c] = curr
                if row[c] == '#':
                    curr += 1
                    
            for c in range(M):
                if row[c] == '-':
                    aura = left_counts[c] if left_counts[c] < right_counts[c] else right_counts[c]
                    u = r + c
                    v = r - c + M - 1
                    points.append(Point(r, c, u, v, aura))
        
        u_min = min(p.u for p in points)
        u_max = max(p.u for p in points)
        v_min = min(p.v for p in points)
        v_max = max(p.v for p in points)
        
        for p in points:
            p.u -= u_min
            p.v -= v_min
            
        U = u_max - u_min + 1
        V = v_max - v_min + 1
        
        pref = [0] * (U * V)
        row_has_point = [False] * U
        col_has_point = [False] * V
        
        for p in points:
            pref[p.u * V + p.v] = 1
            row_has_point[p.u] = True
            col_has_point[p.v] = True
            
        for i in range(U):
            row_idx = i * V
            for j in range(1, V):
                pref[row_idx + j] += pref[row_idx + j - 1]
                
        for i in range(1, U):
            curr_idx = i * V
            prev_idx = (i - 1) * V
            for j in range(V):
                pref[curr_idx + j] += pref[prev_idx + j]
                
        def get_count(i, j, D):
            if i < 0 or j < 0: return 0
            if i >= U: i = U - 1
            if j >= V: j = V - 1
            
            i_D = i - D - 1
            j_D = j - D - 1
            
            ans = pref[i * V + j]
            if i_D >= 0:
                ans -= pref[i_D * V + j]
            if j_D >= 0:
                ans -= pref[i * V + j_D]
            if i_D >= 0 and j_D >= 0:
                ans += pref[i_D * V + j_D]
            return ans
            
        def check(D):
            valid_cols = [j for j in range(V) if col_has_point[j] and get_count(U-1, j, D) >= K]
            if not valid_cols: return False
            
            for i in range(U):
                if not row_has_point[i]: continue
                if get_count(i, V-1, D) < K: continue
                for j in valid_cols:
                    if get_count(i, j, D) >= K:
                        return True
            return False
            
        low = 0
        high = max(U, V)
        ans_D = high
        
        while low <= high:
            mid = (low + high) // 2
            if check(mid):
                ans_D = mid
                high = mid - 1
            else:
                low = mid + 1
                
        valid_cols = [j for j in range(V) if col_has_point[j] and get_count(U-1, j, ans_D) >= K]
        valid_boxes = []
        for i in range(U):
            if not row_has_point[i]: continue
            if get_count(i, V-1, ans_D) < K: continue
            for j in valid_cols:
                if get_count(i, j, ans_D) >= K:
                    valid_boxes.append((i, j))
                    
        points_u = sorted(points, key=lambda p: p.u)
        u_vals = [p.u for p in points_u]
        
        best_overall_aura = float('inf')
        best_overall_points = None
        
        for i, j in valid_boxes:
            left_u = i - ans_D
            right_u = i
            left_v = j - ans_D
            right_v = j
            
            idx_start = bisect_left(u_vals, left_u)
            idx_end = bisect_right(u_vals, right_u)
            
            box_points = []
            for k_idx in range(idx_start, idx_end):
                pt = points_u[k_idx]
                if left_v <= pt.v <= right_v:
                    box_points.append(pt)
                    
            box_points.sort(key=lambda p: (p.aura, p.r, p.c))
            best_K = box_points[:K]
            
            current_aura = sum(p.aura for p in best_K)
            if current_aura < best_overall_aura:
                best_overall_aura = current_aura
                best_overall_points = best_K
                
        for p in best_overall_points:
            out.append(f"{p.r} {p.c}")
            
    print('\n'.join(out))

if __name__ == '__main__':
    solve()