import sys
from fractions import Fraction
input = sys.stdin.readline

def build_factory(P, A, B):
    """
    Build a factory that collects exactly P/(2^A * 3^B) of items.
    
    Layout: 5 rows, splitters at row 2 (interior, not adjacent to edge rows 0,4)
    
    Row 0: top exit row ('^' tiles allow items to exit top = collected)
    Row 1: upper helper row
    Row 2: main belt (going right), splitters here
    Row 3: lower helper row  
    Row 4: bottom exit row ('v' tiles allow items to exit bottom = collected)
    
    Each stage k uses columns [2k, 2k+1]:
      col 2k:   '>' feeder
      col 2k+1: 'S' splitter with up/down configured based on collect count
    
    After last stage, col 2*(A+B) is the terminal (collected or destroyed).
    
    Splitter S at (2, c):
      - Right (2,c+1): '>' always valid output (continues)
      - Up (1,c): '^' → items go to (0,c)='^' → exit top = COLLECTED (valid output)
                  'X' → items destroyed (valid output)
                  'v' → points down toward S → INVALID (back-pointer, not output)
      - Down (3,c): 'v' → items go to (4,c)='v' → exit bottom = COLLECTED (valid output)
                   'X' → items destroyed (valid output)  
                   '^' → points up toward S → INVALID (back-pointer)
    
    2-way splitter (halving): need exactly 2 valid outputs.
      Collect 1/2: up='^'(collect), right='>'(continue), down='^'(invalid) → 2-way
      Destroy 1/2: up='X'(destroy), right='>'(continue), down='^'(invalid) → 2-way
    
    3-way splitter (thirding): need exactly 3 valid outputs.
      Collect 0: up='X'(destroy), down='X'(destroy), right='>'(continue) → 3-way
      Collect 1: up='^'(collect), down='X'(destroy), right='>'(continue) → 3-way
      Collect 2: up='^'(collect), down='v'(collect), right='>'(continue) → 3-way
    """
    
    target = Fraction(P, (2**A) * (3**B))
    
    # Compute stages greedily
    # Process B thirding stages, then A halving stages
    stage_list = []
    remaining = target
    flow = Fraction(1)
    
    for _ in range(B):
        one_third = flow / 3
        # How many thirds to collect? 0, 1, or 2
        # c = floor(remaining / one_third), capped at 2
        if one_third == 0:
            c = 0
        else:
            c = min(2, int(remaining / one_third))
        stage_list.append(('3', c))
        remaining -= c * one_third
        flow = one_third  # 1/3 continues
    
    for _ in range(A):
        half = flow / 2
        # Collect 0 or 1 halves
        if remaining >= half - Fraction(1, 10**18):  # collect if possible
            c = 1
        else:
            c = 0
        stage_list.append(('2', c))
        remaining -= c * half
        flow = half  # 1/2 continues
    
    # After all stages, remaining should be 0
    # If not, the leftover must equal flow (collect all remaining flow at end)
    final_collect = (remaining > 0)
    
    # Sanity check
    assert remaining == 0 or remaining == flow, f"remaining={remaining}, flow={flow}, target={target}"
    
    # Build the grid
    n_stages = A + B
    # Columns: stages at cols 1, 3, 5, ..., 2*n_stages-1
    # Plus col 0 (initial feeder) and col 2*n_stages (terminal)
    M = 2 * n_stages + 1  # total columns
    N = 5  # rows
    
    g = [['.' for _ in range(M)] for _ in range(N)]
    
    # Main belt: row 2
    for c in range(M):
        g[2][c] = '>'
    
    # Place each stage
    for k, (stype, sc) in enumerate(stage_list):
        sc_col = 2 * k + 1  # splitter column (odd: 1, 3, 5, ...)
        
        g[2][sc_col] = 'S'
        # g[2][sc_col-1] = '>' already set
        # g[2][sc_col+1] = '>' already set (continue)
        
        if stype == '2':
            # 2-way: right continues, up or destroy, down=invalid (back-pointer '^')
            g[3][sc_col] = '^'  # points up toward S → invalid output → makes it 2-way
            if sc == 1:
                # Collect via up
                g[1][sc_col] = '^'
                g[0][sc_col] = '^'
            else:
                # Destroy via up
                g[1][sc_col] = 'X'
        else:  # '3'
            # 3-way: right continues, up and down are additional outputs
            if sc == 0:
                g[1][sc_col] = 'X'   # destroy up
                g[3][sc_col] = 'X'   # destroy down
            elif sc == 1:
                g[1][sc_col] = '^'   # collect up
                g[0][sc_col] = '^'
                g[3][sc_col] = 'X'   # destroy down
            else:  # sc == 2
                g[1][sc_col] = '^'   # collect up
                g[0][sc_col] = '^'
                g[3][sc_col] = 'v'   # collect down
                g[4][sc_col] = 'v'
    
    # Terminal column: col 2*n_stages
    terminal_col = 2 * n_stages
    if final_collect:
        # Items exit right edge at (2, M-1) = collected (right edge, pointing right)
        g[2][terminal_col] = '>'  # already set, exits right = collected
    else:
        # Destroy remaining flow
        g[2][terminal_col] = 'X'
    
    # Output
    lines = [f"{N} {M}"]
    for row in g:
        lines.append(''.join(row))
    return '\n'.join(lines)

T = int(input())
for _ in range(T):
    P, A, B = map(int, input().split())
    print(build_factory(P, A, B))