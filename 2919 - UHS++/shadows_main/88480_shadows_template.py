import time
def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimumimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    


    minimum = 0
    for i in range(N):
        minimum += max(S1[i].count("#"), S2[i].count("#"))
    
    maximum = 0
    for row in range(N):
        # totalDots = S1[row].count(".") + S2[row].count(".")
        # maximum -= totalDots * N
        # if totalDots > 1:
        #     maximum += totalDots - 1
        maximum += S1[row].count("#") * S2[row].count("#")

    return maximum, minimum


def main():
    T = int(input())
    # time.sleep(1)
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
