import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    it = iter(input_data)
    try:
        t_str = next(it)
    except StopIteration:
        return
    
    t = int(t_str)
    
    for _ in range(t):
        n = int(next(it))
        m = int(next(it))
        k = int(next(it))
        
        grid = [next(it) for _ in range(n)]
        available_seats = []
        
        for r in range(n):
            row = grid[r]
            left_a = [0] * m
            curr_left = 0
            for c in range(m):
                left_a[c] = curr_left
                if row[c] == '#':
                    curr_left += 1
            
            curr_right = 0
            for c in range(m - 1, -1, -1):
                if row[c] == '-':
                    aura = min(left_a[c], curr_right)
                    available_seats.append({
                        'r': r, 'c': c, 
                        'u': r + c, 'v': r - c, 
                        'aura': aura
                    })
                if row[c] == '#':
                    curr_right += 1

        available_seats.sort(key=lambda x: x['u'])
        
        best_coords = []
        
        def check_valid(d):
            nonlocal best_coords
            min_aura_sum = float('inf')
            found = False
            
            left = 0
            for right in range(len(available_seats)):
                while available_seats[right]['u'] - available_seats[left]['u'] > d:
                    left += 1
                
                if (right - left + 1) >= k:
                    sub_v = sorted(available_seats[left:right+1], key=lambda x: x['v'])
                    
                    v_l = 0
                    for v_r in range(len(sub_v)):
                        while sub_v[v_r]['v'] - sub_v[v_l]['v'] > d:
                            v_l += 1
                        
                        if (v_r - v_l + 1) >= k:
                            found = True
                            auras = [p['aura'] for p in sub_v[v_l:v_r+1]]
                            # Get K smallest auras efficiently
                            smallest_k_auras = heapq.nsmallest(k, auras)
                            current_sum = sum(smallest_k_auras)
                            
                            if current_sum < min_aura_sum:
                                min_aura_sum = current_sum
                                # Track coordinates only when updating best
                                potential_points = sorted(sub_v[v_l:v_r+1], key=lambda x: x['aura'])
                                best_coords = [(p['r'], p['c']) for p in potential_points[:k]]
            return found

        low, high = 0, n + m
        ans = high
        while low <= high:
            mid = (low + high) // 2
            if check_valid(mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        check_valid(ans)
        for r, c in best_coords:
            sys.stdout.write(f"{r} {c}\n")

if __name__ == "__main__":
    solve()
