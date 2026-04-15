def solve(N, M):
    """
    Create an N x M grid such that every valid cross contains 0-4 exactly once.
    
    Key insight: if grid[r][c] = (2*r + c) % 5, then any cross centered at (r,c)
    has values:
      center:  (2r + c)     % 5  = k
      up:      (2r + c - 2) % 5  = k-2
      down:    (2r + c + 2) % 5  = k+2
      left:    (2r + c - 1) % 5  = k-1
      right:   (2r + c + 1) % 5  = k+1
    These are {k, k±1, k±2} mod 5 = {0,1,2,3,4} ✓
    """
    return [[(2 * r + c) % 5 for c in range(M)] for r in range(N)]


def main():
    T = int(input())
    for _ in range(T):
        temp = input().split()
        N = int(temp[0])
        M = int(temp[1])
        grid = solve(N, M)
        for row in grid:
            print(' '.join(str(x) for x in row))


if __name__ == '__main__':
    main()