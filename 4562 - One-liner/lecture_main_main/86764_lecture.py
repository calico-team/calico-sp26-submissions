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
    aura = [[0] * M for _ in range(N)]
    available_seats = []

    for r in range(N):
        # Count occupied seats to the left
        left_count = [0] * M
        curr = 0
        for c in range(M):
            left_count[c] = curr
            if GRID[r][c] == '#':
                curr += 1

        right_count = [0] * M
        curr = 0
        for c in range(M - 1, -1, -1):
            right_count[c] = curr
            if GRID[r][c] == '#':
                curr += 1

        for c in range(M):
            aura[r][c] = min(left_count[c], right_count[c])
            if GRID[r][c] == '-':
                available_seats.append((r, c))

    best_set = []
    min_max_manhattan = float('inf')
    min_total_aura = float('inf')

    step = max(1, len(available_seats) // 300)
    seeds = available_seats[::step]

    for sr, sc in seeds:
        # Find K nearest available seats to this seed using Dijkstra
        cluster = []
        visited = set()
        pq = [(0, sr, sc)] # (Manhattan distance from seed, r, c)
        visited.add((sr, sc))
        
        total_aura = 0
        
        while pq and len(cluster) < K:
            d, r, c = heapq.heappop(pq)
            if GRID[r][c] == '-':
                cluster.append((r, c))
                total_aura += aura[r][c]
            
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < M and (nr, nc) not in visited:
                    visited.add((nr, nc))
                    # Note: We can traverse through '#' to reach '-' seats
                    heapq.heappush(pq, (abs(nr - sr) + abs(nc - sc), nr, nc))
        
        if len(cluster) == K:
            # Calculate true max Manhattan distance for this specific set
            # Formula: max(|ri-rj| + |ci-cj|) is max of (r+c).max - (r+c).min 
            # and (r-c).max - (r-c).min
            rp = [r + c for r, c in cluster]
            rm = [r - c for r, c in cluster]
            max_dist = max(max(rp) - min(rp), max(rm) - min(rm))
            
            # Primary: Min Max Manhattan | Secondary: Min Total Aura
            if max_dist < min_max_manhattan:
                min_max_manhattan = max_dist
                min_total_aura = total_aura
                best_set = cluster
            elif max_dist == min_max_manhattan:
                if total_aura < min_total_aura:
                    min_total_aura = total_aura
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
