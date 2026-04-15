import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    it = iter(input_data)
    num_test_cases = int(next(it))
    
    for _ in range(num_test_cases):
        N = int(next(it))
        M = int(next(it))
        K = int(next(it))
        
        grid = [next(it) for _ in range(N)]
        
        available_seats = []
        for r in range(N):

            row_str = grid[r]
            left_counts = [0] * M
            right_counts = [0] * M
            
            curr_left = 0
            for c in range(M):
                left_counts[c] = curr_left
                if row_str[c] == '#':
                    curr_left += 1
            
            curr_right = 0
            for c in range(M - 1, -1, -1):
                right_counts[c] = curr_right
                if row_str[c] == '#':
                    curr_right += 1
            
            for c in range(M):
                if row_str[c] == '-':
                    aura_loss = min(left_counts[c], right_counts[c])
                    available_seats.append((r, c, aura_loss))
        
        best_set = []
        min_max_dist = float('inf')
        min_total_aura = float('inf')
        
        def get_best_k_from_window(radius):
            nonlocal best_set, min_max_dist, min_total_aura
            pass

        points = []
        for r, c, aura in available_seats:
            points.append({'r': r, 'c': c, 'u': r + c, 'v': r - c, 'aura': aura})
            
        low = 0
        high = N + M
        final_coords = []
        
        while low <= high:
            mid = (low + high) // 2

            found, current_coords, current_aura = check_dist(mid, points, K)
            if found:
                final_coords = current_coords
                high = mid - 1
            else:
                low = mid + 1
        
        for r, c in final_coords:
            sys.stdout.write(f"{r} {c}\n")

def check_dist(D, points, K):
    """
    Checks if there exists a square of side D in (u, v) space containing K points.
    Returns (True, coordinates, total_aura) if found, prioritizing min_aura.
    """
    if not points: return False, [], 0
    
    # Sort points by u for sliding window
    points.sort(key=lambda p: p['u'])
    
    best_aura = float('inf')
    best_coords = []
    found = False
    
    left = 0
    from bisect import insort, bisect_left
    
    active_v = []
    
    for right in range(len(points)):
        while points[right]['u'] - points[left]['u'] > D:
            left += 1

        if (right - left + 1) >= K:
            sub = points[left:right+1]
            sub.sort(key=lambda p: p['v'])
            
            v_left = 0
            for v_right in range(len(sub)):
                while sub[v_right]['v'] - sub[v_left]['v'] > D:
                    v_left += 1
                
                if (v_right - v_left + 1) >= K:
                    found = True

                    potential = sub[v_left:v_right+1]
                    potential.sort(key=lambda p: p['aura'])
                    current_set = potential[:K]
                    sum_aura = sum(p['aura'] for p in current_set)
                    
                    if sum_aura < best_aura:
                        best_aura = sum_aura
                        best_coords = [(p['r'], p['c']) for p in current_set]
                        
    return found, best_coords, best_aura

if __name__ == "__main__":
    solve()
