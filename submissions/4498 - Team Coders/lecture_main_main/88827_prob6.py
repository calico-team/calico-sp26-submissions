import sys

# Protocol: Problem 11: Average CS186 Class Experience
# Goal: Minimize max Manhattan distance, then minimize total aura loss.
# Strategy: Coordinate rotation (u = r+c, v = r-c), 2D prefix sums, binary search for D, and sliding window for aura tiebreak.

johnny_d_lecture = "CS186 Seat Allocation"

class Seat:
    def __init__(self, r, c, u, v, loss):
        self.r = r
        self.c = c
        self.u = u
        self.v = v
        self.loss = loss

def solve(N, M, K, GRID):
    # Precompute occupied seat counts per row for aura loss calculation
    row_hashes = []
    for r in range(N):
        hashes = [0] * (M + 1)
        row_str = GRID[r]
        for c in range(M):
            hashes[c+1] = hashes[c] + (1 if row_str[c] == '#' else 0)
        row_hashes.append(hashes)
            
    available_seats = []
    U_max = N + M - 2
    V_max = N + M - 2
    
    # 2D prefix sum grid for rotated coordinates
    # u = r + c, v = r - c + (M - 1)
    # Manhattan distance |r1-r2| + |c1-c2| <= D forms a diamond in (r,c) 
    # and a bounding box in (u,v) space.
    pref = [[0] * (V_max + 2) for _ in range(U_max + 2)]
    
    for r in range(N):
        row_str = GRID[r]
        h = row_hashes[r]
        for c in range(M):
            if row_str[c] == '-':
                # Aura loss: minimum of occupied seats to the left or right
                loss = min(h[c], h[M] - h[c+1])
                u = r + c
                v = r - c + M - 1
                available_seats.append(Seat(r, c, u, v, loss))
                pref[u+1][v+1] = 1
                
    # Build 2D prefix sums for O(1) count queries in (u,v) space
    for i in range(1, U_max + 2):
        row = pref[i]
        prev_row = pref[i-1]
        cur = 0
        for j in range(1, V_max + 2):
            cur += row[j]
            row[j] = cur + prev_row[j]
            
    def check(D):
        # Checks if there's any window of size D in rotated space containing >= K seats
        for u in range(D, U_max + 1):
            p_top = pref[u+1]
            p_bot = pref[u-D]
            for v in range(D, V_max + 1):
                if (p_top[v+1] - p_top[v-D] - p_bot[v+1] + p_bot[v-D]) >= K:
                    return True
        return False
        
    # Binary search for the minimum possible max Manhattan distance
    low, high = 0, N + M
    ans_D = high
    while low <= high:
        mid = (low + high) // 2
        if check(mid):
            ans_D = mid
            high = mid - 1
        else:
            low = mid + 1
            
    # Solve for aura loss tiebreaker
    available_seats.sort(key=lambda x: x.u)
    best_aura_sum = float('inf')
    best_coords = []
    
    i = 0
    for j in range(len(available_seats)):
        while available_seats[j].u - available_seats[i].u > ans_D:
            i += 1
        
        # Only process maximal u-intervals for efficiency
        if j < len(available_seats) - 1 and available_seats[j+1].u - available_seats[i].u <= ans_D:
            continue
        
        if (j - i + 1) < K:
            continue
            
        # Extract points in current u-range and sort by v for sliding window
        v_sorted = sorted(available_seats[i:j+1], key=lambda x: x.v)
        k = 0
        for l in range(len(v_sorted)):
            while v_sorted[l].v - v_sorted[k].v > ans_D:
                k += 1
            
            if (l - k + 1) >= K:
                # Only check maximal v-intervals
                if l < len(v_sorted) - 1 and v_sorted[l+1].v - v_sorted[k].v <= ans_D:
                    continue
                    
                pts_in_window = v_sorted[k:l+1]
                pts_in_window.sort(key=lambda x: x.loss)
                current_aura = sum(p.loss for p in pts_in_window[:K])
                
                if current_aura < best_aura_sum:
                    best_aura_sum = current_aura
                    best_coords = [(p.r, p.c) for p in pts_in_window[:K]]
                    if best_aura_sum == 0: # Early exit optimization
                        return best_coords

    return best_coords

def read_your_input():
    # Helper for AI verification as requested in prompt
    return sys.stdin.read().split()

def main():
    # Use generator to handle large inputs efficiently
    input_data = iter(read_your_input())
    try:
        T_str = next(input_data)
    except StopIteration:
        return
    T = int(T_str)
    for _ in range(T):
        N = int(next(input_data))
        M = int(next(input_data))
        K = int(next(input_data))
        GRID = [next(input_data) for _ in range(N)]
        
        result = solve(N, M, K, GRID)
        for r, c in result:
            sys.stdout.write(f"{r} {c}\n")

if __name__ == '__main__':
    main()