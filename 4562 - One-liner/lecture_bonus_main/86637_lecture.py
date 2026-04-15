import sys, heapq

def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    # YOUR CODE HERE
    #empty_seats = [["-" for _ in range(M)] for _ in range(N)]
    # 1. Pre-calculate Aura Loss
    aura = [[0] * M for _ in range(N)]
    available = []
    for r in range(N):
        left = [0] * M
        count = 0
        for c in range(M):
            left[c] = count
            if GRID[r][c] == '#': count += 1
        
        right = [0] * M
        count = 0
        for c in range(M - 1, -1, -1):
            right[c] = count
            if GRID[r][c] == '#': count += 1
            
        for c in range(M):
            aura[r][c] = min(left[c], right[c])
            if GRID[r][c] == '-':
                available.append((r, c))

    best_set = []
    min_max_d = float('inf')
    min_aura_sum = float('inf')

    # Optimization: If K is small, we check all seeds. If K is large, 
    # the search space is tighter.
    seeds = available if len(available) < 400 else available[::len(available)//400]

    for sr, sc in seeds:
        # Find K nearest available seats
        cluster = []
        # Dijkstra-like BFS using Manhattan distance from seed
        pq = [(0, sr, sc)]
        visited = {(sr, sc)}
        curr_aura = 0
        
        while pq and len(cluster) < K:
            d, r, c = heapq.heappop(pq)
            if GRID[r][c] == '-':
                cluster.append((r, c))
                curr_aura += aura[r][c]
            
            # Pruning: If distance from seed is already worse than our best max_d
            if d > min_max_d: break

            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < M and (nr, nc) not in visited:
                    visited.add((nr, nc))
                    heapq.heappush(pq, (abs(nr - sr) + abs(nc - sc), nr, nc))

        if len(cluster) == K:
            # Efficient Max Manhattan Distance calculation
            rs_plus_cs = [r + c for r, c in cluster]
            rs_minus_cs = [r - c for r, c in cluster]
            res_d = max(max(rs_plus_cs) - min(rs_plus_cs), max(rs_minus_cs) - min(rs_minus_cs))
            
            if res_d < min_max_d:
                min_max_d = res_d
                min_aura_sum = curr_aura
                best_set = cluster
            elif res_d == min_max_d:
                if curr_aura < min_aura_sum:
                    min_aura_sum = curr_aura
                    best_set = cluster
                    
    return best_set

    #print(GRID, len(available_seats))
    #return [(0, 0) for _ in range(K)]


def main():
    T = int(input())
    for _ in range(T):
        N, M, K = map(int, input().split())
        GRID = []
        for _ in range(N):
            GRID.append(input().strip())
        result = solve(N, M, K, GRID)
        for r, c in result:
            print(f"{r} {c}")


if __name__ == '__main__':
    main()
