def solve(N, M, K, GRID):
    """
    N: number of rows in the lecture hall
    M: number of columns in the lecture hall
    K: number of friends who need seats
    GRID: list of N strings of length M; '#' is a blocked seat, '-' is an empty seat

    Return a list of K (row, col) tuples for the chosen seats.
    """
    seatsAvail = []
    for r in range(N):
        row_str = GRID[r]
        occupeidIdx = []
        for i in range(M):
            if row_str[i] == '#':
                occupeidIdx.append(i) 
        for c in range(M):
            if row_str[c] == '-':
                lOccupeid = 0
                for idx in occupeidIdx:
                    if idx < c:
                        lOccupeid += 1
                ROccupeid = len(occupeidIdx) - lOccupeid
                if lOccupeid < ROccupeid:
                    aura_loss = lOccupeid
                else:
                    aura_loss = ROccupeid
                seatsAvail.append((aura_loss, r, c))
    seatsAvail.sort()
    result = []
    for i in range(K):
        result.append((seatsAvail[i][1], seatsAvail[i][2]))
    return result
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