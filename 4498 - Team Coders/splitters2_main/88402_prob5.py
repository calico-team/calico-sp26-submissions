import sys

def solve(P, A, B):
    """
    Build a factory with N rows and M columns that produces the target rate.
    Uses a mixed-radix spine to partition the flow into P units.
    """
    # Define the sequence of splits (Threes first, then Twos)
    K = [3] * B + [2] * A
    S = len(K)
    
    # Calculate how many units to 'siphon off' at each stage to reach P
    # We ensure at least 1 unit remains in the spine until the end (rem >= 1)
    c = []
    rem = P
    vals = [1] * (S + 1)
    for i in range(S - 1, -1, -1):
        vals[i] = vals[i+1] * K[i]
        
    for i in range(S - 1):
        v = vals[i+1] # The value of one side-branch at this depth
        # Take as many branches as possible without emptying the spine
        ci = (rem - 1) // v
        if ci > K[i] - 1:
            ci = K[i] - 1
        c.append(ci)
        rem -= ci * v
    
    # Final remaining units to collect at the very last splitter
    final_rem = rem
    
    # Grid dimensions: N rows by 5 columns
    N = 2 * S + 3
    M = 5
    grid = [['.' for _ in range(M)] for _ in range(N)]
    
    # Entrance path to the first splitter
    grid[0][0] = '>'
    grid[0][1] = '>'
    grid[0][2] = 'v'
    grid[1][2] = 'v'
    
    # Build the Spine
    for i in range(S):
        r = 2 * i + 2
        ki = K[i]
        grid[r][2] = 'S'
        
        # Determine how many branches to collect at this stage
        to_collect = final_rem if i == S - 1 else c[i]
        
        # 1. Left Branch (Only for base-3 splitters)
        if ki == 3:
            grid[r][1] = '<'
            if to_collect > 0:
                grid[r][0] = '<' # Point out (Collect)
                to_collect -= 1
            else:
                grid[r][0] = 'X' # Destroy
        
        # 2. Right Branch (For both base-2 and base-3)
        grid[r][3] = '>'
        if to_collect > 0:
            grid[r][4] = '>' # Point out (Collect)
            to_collect -= 1
        else:
            grid[r][4] = 'X' # Destroy
            
        # 3. Down Branch (Continue spine or final collection)
        if i < S - 1:
            grid[r+1][2] = 'v' # Continue to next splitter
        else:
            # Final stage: does the remainder go to the edge or X?
            if to_collect > 0:
                grid[r+1][2] = 'v'
                grid[r+2][2] = 'v' # Point out bottom edge
            else:
                grid[r+1][2] = 'X'
                
    return ["".join(row) for row in grid]


def main():
    # Use fast I/O for 50 test cases
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    idx = 1
    for _ in range(T):
        P = int(input_data[idx])
        A = int(input_data[idx+1])
        B = int(input_data[idx+2])
        idx += 3
        
        factory = solve(P, A, B)
        N = len(factory)
        M = len(factory[0])
        print(N, M)
        for row in factory:
            print(row)


if __name__ == '__main__':
    main()