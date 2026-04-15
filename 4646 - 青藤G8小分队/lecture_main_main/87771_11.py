def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    
    for _ in range(T):
        N = int(input[ptr])
        M = int(input[ptr+1])
        K = int(input[ptr+2])
        ptr +=3
        
        grid = []
        for _ in range(N):
            grid.append(input[ptr])
            ptr +=1
        
        # Collect all available seats
        seats = []
        for r in range(N):
            for c in range(M):
                if grid[r][c] == '-':
                    seats.append( (r, c) )
        
        if K == 1:
            print(seats[0][0], seats[0][1])
            continue
        
        # Precompute left and right counts for aura loss
        left_counts = []  # left[r][c]: number of '#' in row r, columns 0..c-1
        right_counts = [] # right[r][c]: number of '#' in row r, columns c..M-1
        for r in range(N):
            row = grid[r]
            left = [0] * (M + 1)
            for c in range(M):
                left[c+1] = left[c] + (1 if row[c] == '#' else 0)
            left_counts.append(left)
            
            right = [0] * (M + 1)
            for c in range(M-1, -1, -1):
                right[c] = right[c+1] + (1 if row[c] == '#' else 0)
            right_counts.append(right)
        
        # Binary search for minimal D
        low = 0
        high = (N-1) + (M-1)
        
        while low < high:
            mid = (low + high) // 2
            possible = False
            
            # Check all possible row differences dr
            for dr in range(0, mid + 1):
                if possible:
                    break
                # Iterate all possible r_start
                for r_start in range(N - dr):
                    if possible:
                        break
                    r_end = r_start + dr
                    # Collect columns of available seats in this row range
                    cols = []
                    for r in range(r_start, r_end + 1):
                        for c in range(M):
                            if grid[r][c] == '-':
                                cols.append(c)
                    # Sort columns
                    cols.sort()
                    # Sliding window to find if K seats fit
                    n = len(cols)
                    if n < K:
                        continue
                    l = 0
                    for r_idx in range(n):
                        while cols[r_idx] - cols[l] > (mid - dr):
                            l += 1
                        if r_idx - l + 1 >= K:
                            possible = True
                            break
            
            if possible:
                high = mid
            else:
                low = mid + 1
        
        D = low
        
        # Find the best seats with minimal aura loss
        best_total = float('inf')
        best_seats = None
        
        for dr in range(0, D + 1):
            for r_start in range(N - dr):
                r_end = r_start + dr
                # Collect seats with their aura loss
                current_seats = []
                for r in range(r_start, r_end + 1):
                    for c in range(M):
                        if grid[r][c] == '-':
                            al = min(left_counts[r][c], right_counts[r][c+1])
                            current_seats.append( (al, r, c) )
                # Sort by column
                current_seats.sort(key=lambda x: x[2])
                # Sliding window
                n = len(current_seats)
                if n < K:
                    continue
                l = 0
                for r_idx in range(n):
                    while current_seats[r_idx][2] - current_seats[l][2] > (D - dr):
                        l += 1
                    if r_idx - l + 1 >= K:
                        # Extract window and sort by aura loss
                        window = current_seats[l : r_idx+1]
                        window.sort(key=lambda x: x[0])
                        selected = window[:K]
                        total = sum(s[0] for s in selected)
                        if total < best_total:
                            best_total = total
                            best_seats = [ (s[1], s[2]) for s in selected ]
        
        # Output the best seats
        for seat in best_seats:
            print(seat[0], seat[1])

if __name__ == "__main__":
    main()
