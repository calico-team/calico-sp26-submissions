def solve(P, A, B):
    """
    Build a factory with N rows and M columns that produces the target rate.
    
    P: the target numerator of the fraction P / (2^A * 3^B)
    A: the exponent of 2 in the denominator
    B: the exponent of 3 in the denominator
    """
    # Create the radices array: A times 2, followed by B times 3
    radices = [2] * A + [3] * B
    
    # Extract the required mixed-radix digits from right to left
    curr_P = P
    digits = []
    for r in reversed(radices):
        digits.append(curr_P % r)
        curr_P = curr_P // r
    
    # Reverse to match left-to-right processing in the bus
    digits.reverse()
    
    # Grid dimensions
    K = A + B
    M = 2 * K + 3
    grid = [['.' for _ in range(M)] for _ in range(5)]
    
    # Entry route from (0,0) down to the main bus at row 2
    grid[0][0] = '>'
    grid[0][1] = 'v'
    grid[1][1] = 'v'
    grid[2][1] = '>'
    
    # Build each splitter stage along the bus
    for i in range(K):
        r = radices[i]
        d = digits[i]
        col = 2 * i + 2
        
        # The main bus components
        grid[2][col] = 'S'
        grid[2][col+1] = '>'
        
        if r == 2:
            # Split by 2: Only 1 value branch is generated (UP)
            if d == 1:
                grid[1][col] = '^'
                grid[0][col] = '^'  # Collected at top edge
            else:
                grid[1][col] = 'X'  # Destroyed
        elif r == 3:
            # Split by 3: 2 value branches are generated (UP and DOWN)
            if d == 2:
                grid[1][col] = '^'
                grid[0][col] = '^'  # 1st fraction collected at top edge
                grid[3][col] = 'v'
                grid[4][col] = 'v'  # 2nd fraction collected at bottom edge
            elif d == 1:
                grid[1][col] = '^'
                grid[0][col] = '^'  # 1st fraction collected at top edge
                grid[3][col] = 'X'  # 2nd fraction destroyed
            else:
                grid[1][col] = 'X'  # 1st fraction destroyed
                grid[3][col] = 'X'  # 2nd fraction destroyed
                
    # The final leftover bus flow is always destroyed (since P < 2^A * 3^B)
    grid[2][M-1] = 'X'
    
    # Convert the 2D array of characters into a list of strings
    return ["".join(row) for row in grid]


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