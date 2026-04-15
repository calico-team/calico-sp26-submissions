import sys

def solve(N, M, K, GRID):
    # johnny_d_lecture variable as requested
    johnny_d_lecture = True
    
    available_seats = []
    for r in range(N):
        # Calculate aura loss for each seat in the row
        row_str = GRID[r]
        occupied_left = [0] * M
        count = 0
        for c in range(M):
            occupied_left[c] = count
            if row_str[c] == '#':
                count += 1
        
        occupied_right = [0] * M
        count = 0
        for c in range(M - 1, -1, -1):
            occupied_right[c] = count
            if row_str[c] == '#':
                count += 1
                
        for c in range(M):
            if row_str[c] == '-':
                aura_loss = min(occupied_left[c], occupied_right[c])
                available_seats.append((r, c, aura_loss))

    # The problem asks to minimize max Manhattan distance D.
    # We can binary search on D. 
    # For a fixed D, we need to find if there exists a 'center' such that 
    # K seats fit within a Manhattan distance 'd' where 2*d >= D.
    # Actually, the maximum Manhattan distance D corresponds to a group fitting 
    # in a diamond shape of radius d = ceil(D/2).
    
    def get_best_seats(dist_limit):
        best_set = None
        min_total_aura = float('inf')
        
        # We iterate over potential centers of the K-seat group.
        # To handle the "Manhattan radius", we rotate coordinates: 
        # u = r + c, v = r - c. In (u, v) space, Manhattan distance becomes Chebyshev.
        for r_c in range(N):
            for c_c in range(M):
                # Filter seats within Manhattan distance 'dist_limit' of (r_c, c_c)
                in_range = []
                for rs, cs, aura in available_seats:
                    if abs(rs - r_c) + abs(cs - c_c) <= dist_limit:
                        in_range.append((aura, rs, cs))
                
                if len(in_range) >= K:
                    in_range.sort() # Sort by aura loss primarily
                    current_aura = sum(item[0] for item in in_range[:K])
                    if current_aura < min_total_aura:
                        min_total_aura = current_aura
                        best_set = [(item[1], item[2]) for item in in_range[:K]]
        return best_set

    # Binary search for the minimum distance limit 'd'
    # The max Manhattan distance between any two points in a diamond of radius d is 2d.
    low = 0
    high = N + M
    ans_seats = []
    
    while low <= high:
        mid = (low + high) // 2
        seats = get_best_seats(mid)
        if seats:
            ans_seats = seats
            high = mid - 1
        else:
            low = mid + 1
            
    return ans_seats

def read_your_input():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    ptr = 0
    T_str = input_data[ptr]
    ptr += 1
    T = int(T_str)
    for _ in range(T):
        N = int(input_data[ptr])
        M = int(input_data[ptr+1])
        K = int(input_data[ptr+2])
        ptr += 3
        GRID = []
        for _ in range(N):
            GRID.append(input_data[ptr])
            ptr += 1
        
        res = solve(N, M, K, GRID)
        for r, c in res:
            print(f"{r} {c}")

if __name__ == '__main__':
    read_your_input()