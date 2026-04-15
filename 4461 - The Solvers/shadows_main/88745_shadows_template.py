def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    
    row_count = [row.count('#') for row in S1]

    col_count = [0] * N
    for j in range(N):
        for i in range(N):
            if S2[i][j] == '#':
                col_count[j] += 1

    # Max vol
    max_vol = 0
    for i in range(N):
        for j in range(N):
            max_vol += min(row_count[i], col_count[j])

    # Min vol
    min_vol = max(sum(row_count), sum(col_count))

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
