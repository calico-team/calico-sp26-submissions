def solve(N, M, K, grid):
    """
    Find K available seats that minimize maximum Manhattan distance.
    For bonus: also minimize total aura loss as tiebreaker.
    """
    available = []
    for i in range(N):
        for j in range(M):
            if grid[i][j] == '-':
                available.append((i, j))
    
    if K > len(available):
        return available
    if K == 1:
        return available[:1]
    
    # Precompute aura loss
    aura_loss = {}
    for i in range(N):
        left_cnt = 0
        for j in range(M):
            if grid[i][j] == '-':
                aura_loss[(i, j)] = left_cnt
            if grid[i][j] == '#':
                left_cnt += 1
        
        right_cnt = 0
        for j in range(M - 1, -1, -1):
            if grid[i][j] == '#':
                right_cnt += 1
            if grid[i][j] == '-':
                aura_loss[(i, j)] = min(aura_loss[(i, j)], right_cnt)
    
    n = len(available)
    
    # Precompute all pairwise distances
    dist = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            d = abs(available[i][0] - available[j][0]) + abs(available[i][1] - available[j][1])
            dist[i][j] = dist[j][i] = d
    
    def get_max_dist(indices):
        if len(indices) <= 1:
            return 0
        return max(dist[indices[i]][indices[j]] for i in range(len(indices)) for j in range(i + 1, len(indices)))
    
    def get_total_aura(indices):
        return sum(aura_loss[available[idx]] for idx in indices)
    
    def can_form_group(max_d, start_idx):
        """Greedily form a group starting from start_idx with max distance <= max_d"""
        group = [start_idx]
        for idx in range(n):
            if idx == start_idx:
                continue
            # Check if idx is within max_d from ALL members
            if all(dist[idx][g] <= max_d for g in group):
                group.append(idx)
                if len(group) == K:
                    return group
        return group if len(group) == K else None
    
    # Collect unique distances
    distances = set()
    for i in range(n):
        for j in range(i + 1, n):
            distances.add(dist[i][j])
    
    best_solution = None
    best_max_dist = float('inf')
    best_aura = float('inf')
    
    # Try each distance threshold in sorted order
    for max_d in sorted(distances):
        found_at_this_dist = False
        
        # Try starting from each position
        for start in range(n):
            group = can_form_group(max_d, start)
            if group and len(group) == K:
                actual_dist = get_max_dist(group)
                actual_aura = get_total_aura(group)
                
                if actual_dist < best_max_dist or (actual_dist == best_max_dist and actual_aura < best_aura):
                    best_max_dist = actual_dist
                    best_aura = actual_aura
                    best_solution = group
                
                found_at_this_dist = True
        
        # Once found a solution at some distance, we stop (distances are sorted)
        if found_at_this_dist:
            break
    
    if best_solution:
        return [available[idx] for idx in best_solution]
    return available[:K]


def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        grid = [input().strip() for _ in range(N)]
        result = solve(N, M, K, grid)
        for r, c in result:
            print(r, c)


if __name__ == '__main__':
    main()
