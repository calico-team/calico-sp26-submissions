def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    max_vol = 0
    min_vol = 0
    for y in range(N):
        A = sum(1 for x in range(N) if S1[y][x] == '#')
        B = sum(1 for z in range(N) if S2[y][z] == '#')
        max_vol += A * B
        min_vol += max(A, B)
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