def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    
    # Max Volume
    max_vol = 0
    for i in range(N):
        for j in range(N):
            if S1[i][j] == '#' and S2[i][j] == '#':
                max_vol += N

    # Min Volume
    rows_needed = sum(1 for i in range(N) if '#' in S1[i])
    
    cols_needed = 0
    for j in range(N):
        if any(S2[i][j] == '#' for i in range(N)):
            cols_needed += 1

    min_vol = max(rows_needed, cols_needed)

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
