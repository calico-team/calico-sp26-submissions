def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """

    max_vol = 0
    min_vol = 0
    
    for z in range(N):
        count1 = S1[z].count('#')
        count2 = S2[z].count('#')
        max_vol += count1 * count2
        min_vol += max(count1, count2)
    
    return max_vol, min_vol


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input().strip() for _ in range(N)]
        S2 = [input().strip() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()