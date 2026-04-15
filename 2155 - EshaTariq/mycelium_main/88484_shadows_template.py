def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    # YOUR CODE HERE
    max_v = 0
    min_v = 0
    
    for i in range(N):
        # Har row (Z-level) ke hashtags count karein
        c1 = S1[i].count('#')
        c2 = S2[i].count('#')
        
        # Maximal: Product of counts
        max_v += c1 * c2
        
        # Minimal: Maximum of counts (taake dono satisfy hon)
        min_v += max(c1, c2)
            
    return max_v, min_v
    return -1, -1


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()
