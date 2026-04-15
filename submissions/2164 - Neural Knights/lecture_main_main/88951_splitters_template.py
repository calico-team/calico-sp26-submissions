def solve(N, M, K, grid):
    """
    Find K available seats that minimize maximum Manhattan distance.
    For bonus: also minimize total aura loss as tiebreaker.
    """
    # Find all available seats
    available = []
    for i in range(N):
        for j in range(M):
            if grid[i][j] == '-':
                available.append((i, j))
    
    # Calculate aura loss for each seat
    aura_loss = {}
    for i in range(N):
        # Count occupied seats to the left
        left_count = [0] * M
        count = 0
        for j in range(M):
            left_count[j] = count
            if grid[i][j] == '#':
                count += 1
        
        # Count occupied seats to the right
        right_count = [0] * M
        count = 0
        for j in range(M - 1, -1, -1):
            right_count[j] = count
            if grid[i][j] == '#':
                count += 1
        
        for j in range(M):
            if grid[i][j] == '-':
                aura_loss[(i, j)] = min(left_count[j], right_count[j])
    
    def get_max_distance(group):
        """Calculate max Manhattan distance in group"""
        max_d = 0
        for i in range(len(group)):
            for j in range(i + 1, len(group)):
                d = abs(group[i][0] - group[j][0]) + abs(group[i][1] - group[j][1])
                max_d = max(max_d, d)
        return max_d
    
    def get_total_aura(group):
        """Calculate total aura loss for group"""
        return sum(aura_loss[seat] for seat in group)
    
    # Try all combinations using backtracking with pruning
    best_group = None
    best_max_dist = float('inf')
    best_aura = float('inf')
    
    def backtrack(idx, current_group):
        nonlocal best_group, best_max_dist, best_aura
        
        if len(current_group) == K:
            max_dist = get_max_distance(current_group)
            total_aura = get_total_aura(current_group)
            
            if max_dist < best_max_dist or (max_dist == best_max_dist and total_aura < best_aura):
                best_max_dist = max_dist
                best_aura = total_aura
                best_group = current_group[:]
            return
        
        # Pruning: not enough seats left
        if idx >= len(available) or len(available) - idx < K - len(current_group):
            return
        
        # Pruning: if we already found a solution with much smaller distance, skip
        if current_group:
            curr_max = 0
            for i in range(len(current_group)):
                for j in range(i + 1, len(current_group)):
                    d = abs(current_group[i][0] - current_group[j][0]) + abs(current_group[i][1] - current_group[j][1])
                    curr_max = max(curr_max, d)
            if curr_max > best_max_dist:
                return
        
        # Include current seat
        current_group.append(available[idx])
        backtrack(idx + 1, current_group)
        current_group.pop()
        
        # Exclude current seat
        backtrack(idx + 1, current_group)
    
    # For larger inputs, use greedy approach
    if len(available) > 20:
        # Binary search on maximum distance
        distances = set()
        for i in range(len(available)):
            for j in range(i + 1, len(available)):
                d = abs(available[i][0] - available[j][0]) + abs(available[i][1] - available[j][1])
                distances.add(d)
        
        for max_dist in sorted(distances):
            # Try to find K seats with max distance <= max_dist
            for start_idx in range(len(available)):
                group = [available[start_idx]]
                for candidate_idx in range(start_idx + 1, len(available)):
                    candidate = available[candidate_idx]
                    valid = True
                    for member in group:
                        if abs(candidate[0] - member[0]) + abs(candidate[1] - member[1]) > max_dist:
                            valid = False
                            break
                    if valid:
                        group.append(candidate)
                
                if len(group) == K:
                    actual_max_dist = get_max_distance(group)
                    actual_aura = get_total_aura(group)
                    if actual_max_dist < best_max_dist or (actual_max_dist == best_max_dist and actual_aura < best_aura):
                        best_max_dist = actual_max_dist
                        best_aura = actual_aura
                        best_group = group
            
            if best_group is not None:
                break
    else:
        backtrack(0, [])
    
    return best_group if best_group else available[:K]


def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        grid = [input().strip() for _ in range(N)]
        result = solve(N, M, K, grid)
        for r, c in result:
            print(r, c)


def read_your_input():
    """Helper function as required"""
    main()


johnny_d_lecture = None  # Variable as required

if __name__ == '__main__':
    main()
