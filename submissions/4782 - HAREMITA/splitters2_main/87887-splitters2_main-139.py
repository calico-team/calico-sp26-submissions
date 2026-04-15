import sys
input = sys.stdin.readline

def build_grid(P, A, B):
    # Decompose P/(2^A * 3^B) into mixed-radix digits (MSB first).
    # At each stage i with prime p_i: collect k_i out of p_i outputs, pass 1 through.
    # Contribution = k_i / (p_0 * p_1 * ... * p_i). Sum = P/D.
    # Extract digits LSB-first, then reverse to get MSB-first order.
    stages_lsb = []
    p = P
    for _ in range(B):
        stages_lsb.append((3, p % 3))
        p //= 3
    for _ in range(A):
        stages_lsb.append((2, p % 2))
        p //= 2
    stages = list(reversed(stages_lsb))  # MSB first

    # Grid layout: 5 rows, items start at (0,0).
    # (0,0)='v', (1,0)='v', (2,0)='>' route items down to main flow on row 2.
    # Stage i: splitter at col (2i+1), between-stage conveyor at col (2i+2).
    # Final destroy 'X' at col (2n+1). Total M = 2n+2.
    #
    # 2-splitter at (2,c): valid neighbors = up(1,c) + right(2,c+1). Down(3,c)='.'.
    #   k=0: up='X' (destroy), right='>' (continue)
    #   k=1: up='^'->'^' (collect via top exit), right='>' (continue)
    #
    # 3-splitter at (2,c): valid neighbors = up(1,c) + right(2,c+1) + down(3,c).
    #   k=0: up='X', down='X', right='>' (continue)
    #   k=1: up='^'->'^' (collect), down='X', right='>' (continue)
    #   k=2: up='^'->'^' (collect), down='v'->'v' (collect via bottom exit), right='>' (continue)

    n = len(stages)
    M = 2 * n + 2
    grid = [['.' for _ in range(M)] for _ in range(5)]

    # Entry path
    grid[0][0] = 'v'
    grid[1][0] = 'v'
    grid[2][0] = '>'
    # Final destroy
    grid[2][M - 1] = 'X'
    # Between-stage conveyors
    for i in range(n):
        grid[2][2 * i + 2] = '>'

    for i, (prime, k) in enumerate(stages):
        c = 2 * i + 1
        grid[2][c] = 'S'
        if prime == 2:
            # 2-splitter: up + right valid; down='.' (invalid)
            if k == 0:
                grid[1][c] = 'X'
            else:  # k == 1
                grid[1][c] = '^'
                grid[0][c] = '^'
        else:  # prime == 3
            # 3-splitter: up + right + down valid
            if k == 0:
                grid[1][c] = 'X'
                grid[3][c] = 'X'
            elif k == 1:
                grid[1][c] = '^'
                grid[0][c] = '^'
                grid[3][c] = 'X'
            else:  # k == 2
                grid[1][c] = '^'
                grid[0][c] = '^'
                grid[3][c] = 'v'
                grid[4][c] = 'v'

    return [''.join(row) for row in grid]

T = int(input())
for _ in range(T):
    P, A, B = map(int, input().split())
    grid = build_grid(P, A, B)
    print(len(grid), len(grid[0]))
    for row in grid:
        print(row)

def destroy_the_tiles(grid, N, M):
    return [[grid[r][c] == 'X' for c in range(M)] for r in range(N)]

def read_your_input():
    data = sys.stdin.read().split()
    idx = 0
    T = int(data[idx]); idx += 1
    cases = []
    for _ in range(T):
        P, A, B = int(data[idx]), int(data[idx+1]), int(data[idx+2])
        idx += 3
        cases.append((P, A, B))
    return cases