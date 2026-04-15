def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    max_volume = 0
    min_volume = 0

    for row in range(N):
        s1_cnt = S1[row].count('#')
        s2_cnt = S2[row].count('#')

        max_volume += s1_cnt * s2_cnt
        min_volume += max(s1_cnt, s2_cnt)

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
