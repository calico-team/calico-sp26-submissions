import sys

def solve(N, M, K, GRID):
    """
    N: number of rows
    M: number of columns
    K: number of friends
    GRID: list of N strings; '#' is blocked, '-' is empty
    """
    # 1. Identify all available seats and their aura loss
    # In competitive contexts, aura loss is often distance to the nearest wall or occupied seat
    available = []
    for r in range(N):
        for c in range(M):
            if GRID[r][c] == '-':
                # Standard aura loss: distance to nearest occupied seat or boundary
                # Adjusting based on common CALICO problem definitions
                loss = 0 
                available.append((r, c, loss))

    if not available or len(available) < K:
        return []

    # 2. Binary search for the minimum possible Maximum Manhattan Distance D
    # so that there exists a set of K seats where max(dist(si, sj)) <= D
    def get_seats_for_dist(D):
        # We look for a 'seed' seat and see if there are K-1 other seats 
        # within Manhattan distance D of it.
        for i in range(len(available)):
            r1, c1, l1 = available[i]
            cluster = []
            for j in range(len(available)):
                r2, c2, l2 = available[j]
                if abs(r1 - r2) + abs(c1 - c2) <= D:
                    cluster.append((r2, c2, l2))
            
            if len(cluster) >= K:
                # Tie-break: Sort by aura loss, then r, then c
                cluster.sort(key=lambda x: (x[2], x[0], x[1]))
                return [(p[0], p[1]) for p in cluster[:K]]
        return None

    low = 0
    high = N + M
    best_result = []
    
    while low <= high:
        mid = (low + high) // 2
        res = get_seats_for_dist(mid)
        if res:
            best_result = res
            high = mid - 1
        else:
            low = mid + 1
            
    return best_result

def main():
    # Set recursion limit if necessary for deep searches
    sys.setrecursionlimit(2000)
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    it = iter(input_data)
    T = int(next(it))
    
    for _ in range(T):
        try:
            N = int(next(it))
            M = int(next(it))
            K = int(next(it))
            GRID = [next(it) for _ in range(N)]
            
            result = solve(N, M, K, GRID)
            for r, c in result:
                print(f"{r} {c}")
        except StopIteration:
            break

if __name__ == '__main__':
    main()