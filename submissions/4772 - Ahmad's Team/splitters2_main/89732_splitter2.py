def solve(P, A, B):
    """
    Build a factory with N rows and M columns that produces the target rate.
    
    P: the target numerator of the fraction P / (2^A * 3^B)
    A: the exponent of 2 in the denominator
    B: the exponent of 3 in the denominator
    """
    N = A + B + 2
    M = 3
    grid = [['.' for _ in range(M)] for _ in range(N)]
    
    # Starting tile
    grid[0][0] = '>'
    grid[0][1] = 'v'
    
    # Binary splitters (2-way)
    q = P // (3 ** B)
    for i in range(1, A + 1):
        grid[i][1] = 'S'
        grid[i][0] = 'X'                # destroy left output
        bit_index = A - i               # 0 for MSB
        bit = (q >> bit_index) & 1
        if bit:
            grid[i][2] = '>'            # collect right output
        else:
            grid[i][2] = 'X'            # destroy right output
    
    # Ternary splitters (3-way)
    r = P % (3 ** B)
    for j in range(B):
        row = A + 1 + j
        grid[row][1] = 'S'
        digit_index = B - 1 - j
        digit = (r // (3 ** digit_index)) % 3
        # left output
        if digit >= 1:
            grid[row][0] = '<'          # collect left
        else:
            grid[row][0] = 'X'
        # right output
        if digit == 2:
            grid[row][2] = '>'          # collect right
        else:
            grid[row][2] = 'X'
    
    # Destroy the final remaining stream
    grid[A + 1 + B][1] = 'X'
    
    return [''.join(row) for row in grid]


def main():
    T = int(input())
    for _ in range(T):
        P, A, B = map(int, input().split())
        factory = solve(P, A, B)
        N = len(factory)
        M = len(factory[0])
        print(N, M)
        for row in factory:
            print(row)


if __name__ == '__main__':
    main()