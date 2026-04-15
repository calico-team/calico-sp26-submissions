from asyncio.constants import LOG_THRESHOLD_FOR_CONNLOST_WRITES


def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    left = [[0] * N for _ in range(N)]
    right = [[0] * N for _ in range(N)]

    # Left wall is the refreence
    for i in range(N):
        for j in range(N):
            if S1[i][j] == '#':
                left[i][j] = 1
            else:
                left[i][j] = 0
    for i in range(N):
        for j in range(N):
            if S2[i][j] == '#':
                right[i][j] = 1
            else:
                right[i][j] = 0
    max_volume = 0
    min_volume = 0
    right_sum = [sum(row) for row in right]
    left_sum = [sum(row) for row in left]

    max_volume = sum(right_sum[i] * left_sum[i] for i in range(N))
    min_volume = sum(left_sum) + sum(right_sum) - sum(min(left_sum[i], right_sum[i]) for i in range(N))
    
    return max_volume, min_volume


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
