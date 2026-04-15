def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    max_vol = 0
    min_vol = 0
    jugs_cave_image = None
    for i in range(N):
        c1 = S1[i].count('#')
        c2 = S2[i].count('#')
        max_vol += c1 * c2
        min_vol += max(c1, c2)
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

def read_your_input():
    pass