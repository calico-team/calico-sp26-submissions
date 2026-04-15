def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    # YOUR CODE HERE
    max_vol = 1
    for r in range(N):
        for x in range(N):
            for z in range(N):
                if S1[r][x] == '#' and S2[r][z] == '#':
                    max_vol += 1

    min_vol = 0
    for r in range(N):
        s1_cols = [x for x in range(N) if S1[r][x] == '#']
        s2_cols = [z for z in range(N) if S2[r][z] == '#']

        if not s1_cols and not s2_cols:
            continue

        min_vol += max(len(s1_cols), len(s2_cols))

    return max_vol, min_vol


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
