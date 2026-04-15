def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    mv = 0
    mnv = 0

    # Each row in the shadows represents a horizontal slice of the 3D grid
    for r in range(N):
        # Count hashtags (#) in the current row for both shadows
        c = S1[r].count('#')
        c2 = S2[r].count('#')

        # To maximize volume, we fill every possible intersection point in the slice
        mv += (c * c2)

        # To minimize volume, we place blocks such that each hashtag in both 
        # shadows is accounted for by at least one block.
        mnv += max(c, c2)

    return mv, mnv

def main():
    import sys
    input = sys.stdin.read().split()
    if not input:
        return
    
    T = int(input[0])
    idx = 1
    for _ in range(T):
        N = int(input[idx])
        idx += 1
        S1 = input[idx:idx+N]
        idx += N
        S2 = input[idx:idx+N]
        idx += N
        
        result = solve(N, S1, S2)
        print(f"{result[0]} {result[1]}")

if __name__ == '__main__':
    main()