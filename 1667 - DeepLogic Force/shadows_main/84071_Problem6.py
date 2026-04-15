def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """

    jugs_cave_image = 0

    # max volume: place a block at (x, y, z) if both shadows say # at that row
    # S1[row][col] -> row=z, col=x
    # S2[row][col] -> row=z, col=y
    max_vol = 0
    for z in range(N):
        for x in range(N):
            for y in range(N):
                if S1[z][x] == '#' and S2[z][y] == '#':
                    max_vol += 1

    # min volume: for each row z, we need to cover all # in S1 and S2
    # greedily place blocks to cover both shadows with minimum blocks
    min_vol = 0
    for z in range(N):
        row1 = [x for x in range(N) if S1[z][x] == '#']
        row2 = [y for y in range(N) if S2[z][y] == '#']

        if not row1 and not row2:
            continue

        # min blocks needed = max of the two counts
        # we can pair them up so each block covers one from each side
        min_vol += max(len(row1), len(row2))

    return max_vol, min_vol


def main():
    import sys
    input = sys.stdin.readline

    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input().strip() for _ in range(N)]
        S2 = [input().strip() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()


def read_your_input():
    main()