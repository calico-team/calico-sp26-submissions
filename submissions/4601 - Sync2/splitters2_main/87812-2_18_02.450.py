import sys

def solve(P, A, B):
    remaining = P
    
    trit_digits = []
    for i in range(B):
        unit = (1 << A) * (3 ** (B - 1 - i))
        d = remaining // unit
        remaining -= d * unit
        trit_digits.append(d)
    
    bit_digits = []
    for j in range(A):
        unit = 1 << (A - 1 - j)
        d = remaining // unit
        remaining -= d * unit
        bit_digits.append(d)
    
    final_collect = remaining  
    
    total_modules = A + B
    
    
    num_cols = 2 * total_modules + 4
    num_rows = 5
    
    grid = [['.' for _ in range(num_cols)] for _ in range(num_rows)]
    
    
    grid[2][1] = '>'
    
    for k in range(total_modules):
        sc = 2 + 2 * k      
        rc = 3 + 2 * k      
        
        grid[2][sc] = 'S'
        grid[2][rc] = '>'
        
        if k < B:
            
            d = trit_digits[k]
            grid[1][sc] = '^' if d >= 1 else 'X'
            grid[3][sc] = 'v' if d >= 2 else 'X'
        else:
            
            e = bit_digits[k - B]
            grid[1][sc] = '^' if e == 1 else 'X'
            grid[3][sc] = '.' 
    # final exit tile
    final_col = 2 + 2 * total_modules
    if final_collect == 0:
        grid[2][final_col] = 'X'
    
    pass

def solve_clean(P, A, B):
    remaining = P
    
    trit_digits = []
    for i in range(B):
        unit = (1 << A) * (3 ** (B - 1 - i))
        d = remaining // unit
        remaining -= d * unit
        trit_digits.append(d)
    
    bit_digits = []
    for j in range(A):
        unit = 1 << (A - 1 - j)
        d = remaining // unit
        remaining -= d * unit
        bit_digits.append(d)
    
    final_collect = remaining
    
    total_modules = A + B
    
    
    
    num_cols = 2 * total_modules + 3
   
    num_rows = 5
    
    grid = [['.' for _ in range(num_cols)] for _ in range(num_rows)]
    
    
    grid[2][1] = '>'
    
    for k in range(total_modules):
        sc = 2 + 2 * k
        rc = sc + 1
        
        grid[2][sc] = 'S'
        grid[2][rc] = '>'
        
        if k < B:
            d = trit_digits[k]
            grid[1][sc] = '^' if d >= 1 else 'X'
            grid[3][sc] = 'v' if d >= 2 else 'X'
        else:
            e = bit_digits[k - B]
            grid[1][sc] = '^' if e == 1 else 'X'
            
    final_col = 2 * total_modules + 2
    if final_collect == 1:
        grid[2][final_col] = '>'  # exits right edge = collected
    else:
        grid[2][final_col] = 'X'  # destroyed
    
    return grid, num_rows, num_cols

def main():
    data = sys.stdin.read().split()
    idx = 0
    T = int(data[idx]); idx += 1
    
    for _ in range(T):
        P = int(data[idx]); A = int(data[idx+1]); B = int(data[idx+2])
        idx += 3
        
        grid, num_rows, num_cols = solve_clean(P, A, B)
        
        print(f"{num_rows} {num_cols}")
        for row in grid:
            print(''.join(row))

main()

def destroy_the_tiles():
    pass

def read_your_input():
    import sys
    return sys.stdin.read().split()