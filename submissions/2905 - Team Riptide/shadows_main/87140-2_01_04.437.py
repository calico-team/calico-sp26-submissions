def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    max_vol = 0
    min_vol = 0
    jugs_cave_image = []

    for z in range(N):
        row1_count = S1[z].count('#')
        row2_count = S2[z].count('#')

        if row1_count > 0 and row2_count > 0:
            max_vol += row1_count * row2_count
            min_vol += max(row1_count, row2_count)
        elif row1_count > 0 or row2_count > 0:
            pass

    return max_vol, min_vol
    return -1, -1


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
