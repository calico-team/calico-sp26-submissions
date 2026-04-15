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
    
    final_collect = remaining  # 0 or 1
    
    total_modules = A + B
    
    
    row0 = ['.'] * num_cols
    row1 = ['.'] * num_cols
    row2 = ['.'] * num_cols
    
    row1[0] = '.'  # padding so first S not on left edge
    row1[1] = '>'  # start conveyor
    
    for k in range(total_modules):
        sc = 2 + 2 * k   # S column (starts at 2 now)
        rc = 3 + 2 * k   # right conveyor column
        
        row1[sc] = 'S'
        row1[rc] = '>'
        
        if k < B:
            d = trit_digits[k]
            row0[sc] = '^' if d >= 1 else 'X'
            row2[sc] = 'v' if d >= 2 else 'X'
        else:
            e = bit_digits[k - B]
            row0[sc] = '^' if e == 1 else 'X'
            row2[sc] = '.'
    
    if final_collect == 0:
        row1[num_cols - 1] = 'X'
    
    return row0, row1, row2

def main():
    data = sys.stdin.read().split()
    idx = 0
    T = int(data[idx]); idx += 1
    
    for _ in range(T):
        P = int(data[idx]); A = int(data[idx+1]); B = int(data[idx+2])
        idx += 3
        
        row0, row1, row2 = solve(P, A, B)
        n_cols = len(row0)
        # total tiles = 3 * n_cols, max = 3*(2*100+3) = 609 <= 2000 ✓
        print(f"3 {n_cols}")
        print(''.join(row0))
        print(''.join(row1))
        print(''.join(row2))

main()

def destroy_the_tiles():
    pass

def read_your_input():
    import sys
    return sys.stdin.read().split()