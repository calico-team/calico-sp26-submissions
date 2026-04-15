import sys
from fractions import Fraction

input = sys.stdin.readline

def build_factory(P, A, B):
    N_rows = 5
    n_stages = A + B  
    M_cols = 2 * n_stages + 4  
    
    # Initialize grid with '.'
    g = [['.' for _ in range(M_cols)] for _ in range(N_rows)]
    
    # --- FIX 1: Route items from the mandatory top-left start down to the belt ---
    g[0][0] = 'v'
    g[1][0] = 'v'
    
    # Main belt: row 2, going right
    for c in range(M_cols):
        g[2][c] = '>'
        
    stage_list = []
    target = Fraction(P, (2**A) * (3**B))
    remaining2 = target
    flow2 = Fraction(1)
    
    for _ in range(B):
        one_third = flow2 / 3
        c = min(2, int(remaining2 / one_third))
        while c > 0 and c * one_third > remaining2:
            c -= 1
        stage_list.append(('3', c))
        remaining2 -= c * one_third
        flow2 = one_third
    
    for _ in range(A):
        half = flow2 / 2
        if remaining2 >= half:
            c = 1
        else:
            c = 0
        stage_list.append(('2', c))
        remaining2 -= c * half
        flow2 = half
    
    final_collect = (remaining2 > 0)
    
    for k, (stype, sc) in enumerate(stage_list):
        sc_col = 2 * k + 1  
        
        # --- FIX 2: Use lowercase 's' for splitter ---
        g[2][sc_col] = 's' 
        g[2][sc_col - 1] = '>' 
        g[2][sc_col + 1] = '>' 
        
        if stype == '2':
            g[3][sc_col] = '^'  
            if sc == 1:
                g[1][sc_col] = '^'
                g[0][sc_col] = '^'
            else:
                g[1][sc_col] = 'X'
        else:  
            if sc == 0:
                g[1][sc_col] = 'X'
                g[3][sc_col] = 'X'
            elif sc == 1:
                g[1][sc_col] = '^'
                g[0][sc_col] = '^'
                g[3][sc_col] = 'X'
            else:  
                g[1][sc_col] = '^'
                g[0][sc_col] = '^'
                g[3][sc_col] = 'v'
                g[4][sc_col] = 'v'
    
    last_belt_col = 2 * n_stages 
    
    if not final_collect:
        g[2][last_belt_col] = 'X'
        M_cols_actual = last_belt_col + 1
    else:
        M_cols_actual = last_belt_col + 1
    
    g = [row[:M_cols_actual] for row in g]
    
    result = []
    result.append(f"{N_rows} {M_cols_actual}")
    for row in g:
        result.append(''.join(row))
    return '\n'.join(result)

def solve():
    T_str = input().strip()
    if not T_str:
        return
    T = int(T_str)
    for _ in range(T):
        P, A, B = map(int, input().split())
        print(build_factory(P, A, B))

if __name__ == '__main__':
    solve()