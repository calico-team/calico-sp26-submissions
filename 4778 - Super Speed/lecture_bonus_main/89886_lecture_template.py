def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    # YOUR CODE HERE
    
    arr = []
    
    for i in range(N):
        for j in range(M):
            if GRID[i][j] == '-':
                arr.append((i, j))
    
    best = None
    best_val = 10**18
    
    # small optimization: don't try all, just some
    limit = min(len(arr), 200)
    
    for idx in range(limit):
        cx, cy = arr[idx]
        
        tmp = []
        for x, y in arr:
            d = abs(cx - x) + abs(cy - y)
            tmp.append((d, x, y))
        
        tmp.sort()
        
        take = tmp[:K]
        
        # just check farthest from center
        mx = take[-1][0]
        
        if mx < best_val:
            best_val = mx
            best = []
            for _, x, y in take:
                best.append((x, y))
    
    return best


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