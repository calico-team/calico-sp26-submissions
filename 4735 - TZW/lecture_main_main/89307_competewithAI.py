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
                    aura = min(left_counts[c], right_counts[c])
                    available_seats.append({'r': r, 'c': c, 'u': r + c, 'v': r - c, 'aura': aura})

        low = 0
        high = N + M
        best_overall_coords = []

        points_sorted_u = sorted(available_seats, key=lambda p: p['u'])

        while low <= high:
            mid = (low + high) // 2
            found, current_coords = check_valid(mid, points_sorted_u, K)
            if found:
                best_overall_coords = current_coords
                high = mid - 1
            else:
                low = mid + 1
        
        for r, c in best_overall_coords:
            sys.stdout.write(f"{r} {c}\n")

def check_valid(D, points, K):
    best_aura_sum = float('inf')
    best_set = []
    found_any = False
    
    n = len(points)
    left = 0
    for right in range(n):
        while points[right]['u'] - points[left]['u'] > D:
            left += 1
            
        if (right - left + 1) >= K:
            sub = sorted(points[left:right+1], key=lambda p: p['v'])
            v_left = 0
            for v_right in range(len(sub)):
                while sub[v_right]['v'] - sub[v_left]['v'] > D:
                    v_left += 1
                
                if (v_right - v_left + 1) >= K:
                    found_any = True
                    potential = sorted(sub[v_left:v_right+1], key=lambda p: p['aura'])
                    current_aura_sum = sum(p['aura'] for p in potential[:K])
                    
                    if current_aura_sum < best_aura_sum:
                        best_aura_sum = current_aura_sum
                        best_set = [(p['r'], p['c']) for p in potential[:K]]
                        
    return found_any, best_set

if __name__ == "__main__":
    solve()
