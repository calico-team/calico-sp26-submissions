import sys

def solve(P, A, B):
    # Radices sequence: A factors of 2 and B factors of 3
    radices = [2] * A + [3] * B
    k = len(radices)
    
    # Calculate mixed-radix coefficients
    coeffs = [0] * k
    temp_p = P
    for i in range(k - 1, -1, -1):
        coeffs[i] = temp_p % radices[i]
        temp_p //= radices[i]
        
    # Factory Layout: 5 rows
    N = 5
    M = 3 * k + 2
    grid = [['.' for _ in range(M)] for _ in range(N)]
    
    # Entrance
    grid[0][0] = 'v'
    grid[1][0] = 'v'
    grid[2][0] = '>'
    
    # Boundary exits (Arrows pointing out of the grid)
    for j in range(M):
        if grid[0][j] == '.': grid[0][j] = '^'
        if grid[4][j] == '.': grid[4][j] = 'v'
        
    for i in range(k):
        col = 3 * i + 1
        d = radices[i]
        c = coeffs[i]
        
        grid[2][col] = 'S'
        grid[2][col + 1] = '>'
        grid[2][col + 2] = '>'
        
        if i == k - 1:
            grid[2][col + 1] = 'X'
            grid[2][col + 2] = '.'

        if d == 2:
            grid[1][col] = '^' if c == 1 else 'X'
        else: # d == 3
            if c == 0:
                grid[1][col] = 'X'
                grid[3][col] = 'X'
            elif c == 1:
                grid[1][col] = '^'
                grid[3][col] = 'X'
            elif c == 2:
                grid[1][col] = '^'
                grid[3][col] = 'v'
                
    return ["".join(row) for row in grid]

def main():
    # This will open the input box in your IDE
    line1 = input()
    if not line1.strip():
        return
    T_cases = int(line1)

    for _ in range(T_cases):
        line = input()
        parts = line.split()
        if len(parts) < 3:
            continue
            
        P, A, B = map(int, parts)
        
        factory = solve(P, A, B)
        print(f"{len(factory)} {len(factory[0])}")
        for row in factory:
            print(row)

if __name__ == '__main__':
    main()