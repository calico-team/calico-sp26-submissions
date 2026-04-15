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
    
    # store all empty seats
    for i in range(N):
        for j in range(M):
            if GRID[i][j] == '-':
                arr.append((i, j))
    
    best_ans = None
    best_val = 10**18
    
    # try taking each point as kinda center
    for a, b in arr:
        tmp = []
        
        for x, y in arr:
            d = abs(a - x) + abs(b - y)
            tmp.append((d, x, y))
        
        tmp.sort()
        
        take = tmp[:K]
        
        # now check max dist inside this group
        mx = 0
        for i in range(K):
            for j in range(i+1, K):
                x1, y1 = take[i][1], take[i][2]
                x2, y2 = take[j][1], take[j][2]
                
                d = abs(x1 - x2) + abs(y1 - y2)
                if d > mx:
                    mx = d
        
        if mx < best_val:
            best_val = mx
            best_ans = []
            for _, x, y in take:
                best_ans.append((x, y))
    
    return best_ans


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