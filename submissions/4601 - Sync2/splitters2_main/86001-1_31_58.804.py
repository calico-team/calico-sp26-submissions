import sys

def solve(P, A, B):

    
    remaining = P
    
    trit_digits = []
    for i in range(B):
        # at this stage, each unit = 2^A * 3^(B-1-i)
        unit = (1 << A) * (3 ** (B - 1 - i))
        d = remaining // unit
        # d should be 0, 1, or 2
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
    num_cols = 1 + 2 * total_modules + 1  
    num_cols = 2 * total_modules + 1
    
    row0 = ['.'] * num_cols
    row1 = ['.'] * num_cols
    row2 = ['.'] * num_cols
    
    
    row1[0] = '>'
    
    # Place modules
    for k in range(total_modules):
        sc = 1 + 2 * k   
        rc = 2 + 2 * k   
        
        row1[sc] = 'S'
        if rc < num_cols:
            row1[rc] = '>'
        
        if k < B:
            
            d = trit_digits[k]
            
            if d >= 1:
                row0[sc] = '^'  
            else:
                row0[sc] = 'X'
            
            if d >= 2:
                row2[sc] = 'v'  
            else:
                row2[sc] = 'X'
        else:
            
            e = bit_digits[k - B]
            # up: row0[sc]
            if e == 1:
                row0[sc] = '^'  # collected
            else:
                row2[sc] = '.'
    
    # Handle final exit
    last_col = num_cols - 1  # = 2*total_modules
    if final_collect == 0:
        # destroy the final exit
        row1[last_col] = 'X'
    # else: > exits right = collected ✓
    
    return row0, row1, row2

def main():
    data = sys.stdin.read().split()
    idx = 0
    T = int(data[idx]); idx += 1
    
    for _ in range(T):
        P = int(data[idx]); A = int(data[idx+1]); B = int(data[idx+2])
        idx += 3
        
        row0, row1, row2 = solve(P, A, B)
        
        print(f"3 {len(row0)}")
        print(''.join(row0))
        print(''.join(row1))
        print(''.join(row2))

main()

def destroy_the_tiles():
    pass

def read_your_input():
    import sys
    return sys.stdin.read().split()