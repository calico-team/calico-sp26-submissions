def solve(P, A, B):
    """
    Build a factory with N rows and M columns that produces the target rate.
    
    P: the target numerator of the fraction P / (2^A * 3^B)
    A: the exponent of 2 in the denominator
    B: the exponent of 3 in the denominator
    """
    # Create the sequence of divisors: A 2-way splits followed by B 3-way splits
    D = [2] * A + [3] * B
    K = len(D)
    
    # 5 rows is just enough to safely output UP/DOWN without splitters touching edges
    rows = 5
    # Calculate enough columns to fit all splitters and 2 padding columns on the right
    cols = 2 * K + 4
    
    grid = [['.' for _ in range(cols)] for _ in range(rows)]
    
    # Entrance at the top left tile (0, 0)
    grid[0][0] = 'v'
    grid[1][0] = 'v'
    grid[2][0] = '>'
    grid[2][1] = '>'
    
    W_total = (2*A) * (3*B)
    
    for i, d in enumerate(D):
        c = 2 + 2 * i  # Column index of the current splitter
        
        W_next = W_total // d
        q = P // W_next
        r = P % W_next
        
        num_collect = q
        num_next = 1 if r > 0 else 0
        
        # Place the splitter
        grid[2][c] = 's'
        
        # UP output assignment
        if num_collect >= 1:
            grid[1][c] = '^'
            grid[0][c] = '^'  # Points out the top edge (collects)
        else:
            grid[1][c] = 'X'  # Destroys
            
        # DOWN output assignment (only valid for 3-way splitters)
        if d == 3:
            if num_collect >= 2:
                grid[3][c] = 'v'
                grid[4][c] = 'v'  # Points out the bottom edge (collects)
            else:
                grid[3][c] = 'X'  # Destroys
        
        # RIGHT output assignment (Main horizontal bus)
        if num_next == 1:
            grid[2][c+1] = '>'  # Feeds into the next stage
        else:
            grid[2][c+1] = 'X'  # Destroys if we have exactly matched P
            
        # Update P and Weights for the next iteration
        P = r
        W_total = W_next
        
    return ["".join(row) for row in grid]


def main():
    T = int(input())
    for _ in range(T):
        P, A, B = map(int, input().split())
        factory = solve(P, A, B)
        N = len(factory)
        M = len(factory[0])
        print(f"{N} {M}")
        for row in factory:
            print(row)

if __name__ == "__main__":
    main()