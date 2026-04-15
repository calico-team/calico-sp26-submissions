def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    vol_maxx = 0
    vol_min = 0
    
    for i in range(N):
        ch1 = S1[i].count('#')
        ch2 = S2[i].count('#')
        
        vol_maxx += ch1 * ch2
    
        vol_min += max(ch1, ch2)
        
    return vol_maxx, vol_min


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
