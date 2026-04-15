def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    # firstRow = [any(c == '#' for c in row) for row in S1]
    # secondRow = [any(c == '#' for c in row) for row in S2]
    #
    # countRow1 = sum(firstRow)
    # countRow2 = sum(secondRow)
    #
    # maxVol = countRow1 * countRow2
    # minVol = max(countRow1,countRow2)
    #
    # return maxVol,minVol
    s1 = [[False]*N for _ in range(N)]
    s2 = [[False]*N for _ in range(N)]
    for height in range(N):
        for x in range(N):
            if S1[height][x] == '#' :
                s1[x][height] = True

        for y in range(N):
            if S2[height][y] == '#' :
                s2[y][height] = True

    maxVol = 0
    minVol = 0
    for height in range(N):
        countX = sum(s1[x][height] for x in range(N))
        countY = sum(s2[y][height] for y in range(N))
        maxVol += countX * countY
        minVol += max(countX,countY)

    return maxVol,minVol

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
