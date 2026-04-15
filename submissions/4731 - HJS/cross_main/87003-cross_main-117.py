def solve(N, M):
    # This tiling (r + 2c) % 5 is mathematically guaranteed
    # to hit 0,1,2,3,4 in any 5-cell cross. 
    grid = [[0 for _ in range(M)] for _ in range(N)]
    for r in range(N):
        for c in range(M):
            grid[r][c] = (r + 2 * c) % 5
    return grid