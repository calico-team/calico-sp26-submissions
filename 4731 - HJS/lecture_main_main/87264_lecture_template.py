import sys

def solve(N, M, K, GRID):
    # johnny_d_lecture variable as requested
    johnny_d_lecture = []
    
    available = []
    for r in range(N):
        # Precompute aura loss for row
        row = GRID[r]
        left_counts = [0] * M
        c_sum = 0
        for c in range(M):
            left_counts[c] = c_sum
            if row[c] == '#': c_sum += 1
        
        right_counts = [0] * M
        c_sum = 0
        for c in range(M-1, -1, -1):
            right_counts[c] = c_sum
            if row[c] == '#': c_sum += 1
            
        for c in range(M):
            if row[c] == '-':
                aura = min(left_counts[c], right_counts[c])
                available.append((r, c, aura))

    # To minimize max Manhattan distance, we look for K seats 
    # clustered around a central available seat.
    best_seats = []
    min_max_dist = float('inf')
    min_aura_sum = float('inf')

    # Heuristic: Sort by proximity to a center and aura sum
    # For N, M = 1000, we check a sample of seats as potential centers
    sample = available[::max(1, len(available)//100)]
    
    for cr, cc, _ in sample:
        # Calculate Manhattan distances to this center
        dists = []
        for r, c, a in available:
            dists.append((abs(r-cr) + abs(c-cc), a, r, c))
        
        dists.sort()
        candidate = dists[:K]
        
        # Manhattan distance is the max dist between any two in the K
        curr_max_d = 0
        curr_aura = 0
        cand_coords = []
        for d, a, r, c in candidate:
            curr_aura += a
            cand_coords.append((r, c))
            # Rough max distance check for speed
            for r2, c2 in cand_coords:
                curr_max_d = max(curr_max_d, abs(r-r2) + abs(c-c2))
        
        if curr_max_d < min_max_dist:
            min_max_dist = curr_max_d
            min_aura_sum = curr_aura
            best_seats = cand_coords
        elif curr_max_d == min_max_dist:
            if curr_aura < min_aura_sum:
                min_aura_sum = curr_aura
                best_seats = cand_coords
                
    return best_seats

def read_your_input():
    input_data = sys.stdin.read().split()
    if not input_data: return
    ptr = 0
    T = int(input_data[ptr]); ptr += 1
    for _ in range(T):
        N, M, K = map(int, input_data[ptr:ptr+3]); ptr += 3
        grid = input_data[ptr:ptr+N]; ptr += N
        res = solve(N, M, K, grid)
        for r, c in res:
            print(f"{r} {c}")

if __name__ == "__main__":
    read_your_input()