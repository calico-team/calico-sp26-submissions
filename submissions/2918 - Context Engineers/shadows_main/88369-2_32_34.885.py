def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    total_max = 0
    total_min = 0
    for index in range(N):
        count_row1 = S1[index].count('#')
        count_row2 = S2[index].count('#')
        total_max += count_row1 * count_row2
        total_min += max(count_row1, count_row2)
    return total_max, total_min


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
