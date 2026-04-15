def solve(P: int, A: int, B: int) -> list[str]:
    """
    Build a factory with N rows and M columns that produces the target rate.
    
    P: the target numerator of the fraction P / (2^A * 3^B)
    A: the exponent of 2 in the denominator
    B: the exponent of 3 in the denominator
    """
    # Create the sequence of divisors
    divisors = [2] * A + [3] * B
    
    # Calculate the unit value of the side streams at each stage
    stream_values = []
    current_denominator = (2 ** A) * (3 ** B)
    for div in divisors:
        current_denominator //= div
        stream_values.append(current_denominator)
        
    # Greedily determine how many side streams to collect at each stage
    requests = []
    current_p = P
    for i, div in enumerate(divisors):
        max_available = div - 1
        take = min(max_available, current_p // stream_values[i])
        requests.append(take)
        current_p -= take * stream_values[i]
        
    # Any remaining P means the final leftover main bus stream should be collected
    leftover = current_p
    
    # Initialize the grid (N=5 safely avoids placing splitters on the edge)
    num_rows = 5
    num_cols = 2 + 2 * (A + B) + 2
    grid = [['.' for _ in range(num_cols)] for _ in range(num_rows)]
    
    # Route the top-left entrance to the main bus on row 2
    grid[0][0] = 'v'
    grid[1][0] = 'v'
    grid[2][0] = '>'
    grid[2][1] = '>'
    
    col_idx = 2
    for i in range(A + B):
        div = divisors[i]
        req = requests[i]
        
        # Place the splitter
        grid[2][col_idx] = 'S'
        
        if div == 2:
            # 1 side stream available (going down)
            if req == 1:
                grid[3][col_idx] = 'v'
                grid[4][col_idx] = 'v'  # Collect
            else:
                grid[3][col_idx] = 'X'  # Destroy
                
        elif div == 3:
            # 2 side streams available (up and down)
            if req == 2:
                grid[1][col_idx] = '^'
                grid[0][col_idx] = '^'  # Collect Up
                grid[3][col_idx] = 'v'
                grid[4][col_idx] = 'v'  # Collect Down
            elif req == 1:
                grid[1][col_idx] = 'X'  # Destroy Up
                grid[3][col_idx] = 'v'
                grid[4][col_idx] = 'v'  # Collect Down
            else:
                grid[1][col_idx] = 'X'  # Destroy Up
                grid[3][col_idx] = 'X'  # Destroy Down
                
        # Main bus continues
        grid[2][col_idx + 1] = '>'
        col_idx += 2
        
    # Handle the final leftover stream
    if leftover > 0:
        grid[2][col_idx] = '>'
        grid[2][col_idx + 1] = '>'  # Collect by exiting right edge
    else:
        grid[2][col_idx] = 'X'      # Destroy
        
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


if __name__ == '__main__':
    main()