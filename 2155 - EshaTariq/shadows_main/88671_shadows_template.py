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
    for r in range(N):
        # S1 aur S2 ki rows ko as integers count karein
        h1 = [j for j, char in enumerate(S1[r]) if char == '#']
        h2 = [j for j, char in enumerate(S2[r]) if char == '#']
        
        if h1 and h2:
            max_v += len(h1) * len(h2)
            # Minimal volume ke liye dono shadows ke hashtags ka maximum count
            min_v += max(len(h1), len(h2))
            
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
