import sys
from math import gcd
from fractions import Fraction
from collections import deque
input = sys.stdin.readline

def solve(N, M, grid):
    dirs = {'>': (0,1), '<': (0,-1), '^': (-1,0), 'v': (1,0)}

    # Build graph: for each tile, who sends to whom and with what fraction
    # We'll compute in-degree for topological sort
    # Edge: (r,c) -> list of (nr,nc) with fraction multiplier

    # First, compute out-edges and their weights for each tile
    def get_outputs(r, c):
        tile = grid[r][c]
        if tile == 'X' or tile == '.':
            return []
        if tile in dirs:
            dr, dc = dirs[tile]
            nr, nc = r+dr, c+dc
            return [((nr, nc), Fraction(1))]  # may be out-of-bounds
        if tile == 'S':
            valid = []
            for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                nr, nc = r+dr, c+dc
                if 0 <= nr < N and 0 <= nc < M:
                    t = grid[nr][nc]
                    if t == 'X':
                        valid.append((nr, nc))
                    elif t in dirs:
                        ddr, ddc = dirs[t]
                        if not (nr+ddr == r and nc+ddc == c):
                            valid.append((nr, nc))
            k = len(valid)
            return [((nr, nc), Fraction(1, k)) for (nr, nc) in valid]
        return []

    # Compute in-degree for topological sort (only reachable tiles)
    # in_degree counts how many in-grid predecessors send to a tile
    in_degree = {}
    out_edges = {}

    # Only process reachable tiles - guaranteed all non-empty tiles are reachable
    all_tiles = [(r, c) for r in range(N) for c in range(M) if grid[r][c] != '.']

    for r, c in all_tiles:
        if (r, c) not in in_degree:
            in_degree[(r, c)] = 0
        outs = get_outputs(r, c)
        out_edges[(r, c)] = outs
        for ((nr, nc), _) in outs:
            if 0 <= nr < N and 0 <= nc < M:
                in_degree[(nr, nc)] = in_degree.get((nr, nc), 0) + 1

    # Topological sort (BFS/Kahn's)
    frac = {(r, c): Fraction(0) for r, c in all_tiles}
    frac[(0, 0)] = Fraction(1)

    queue = deque()
    for tile in all_tiles:
        if in_degree.get(tile, 0) == 0:
            queue.append(tile)

    collected = Fraction(0)

    while queue:
        r, c = queue.popleft()
        f = frac[(r, c)]
        if grid[r][c] == 'X':
            continue  # destroyed, don't propagate
        for ((nr, nc), weight) in out_edges[(r, c)]:
            if nr < 0 or nr >= N or nc < 0 or nc >= M:
                collected += f * weight
            else:
                frac[(nr, nc)] += f * weight
                in_degree[(nr, nc)] -= 1
                if in_degree[(nr, nc)] == 0:
                    queue.append((nr, nc))

    p = collected.numerator
    q = collected.denominator
    if p == 0:
        print(0, 1)
    else:
        g = gcd(p, q)
        print(p//g, q//g)

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    grid = []
    for _ in range(N):
        grid.append(input().strip())
    solve(N, M, grid)

def destroy_the_tiles(grid, N, M):
    return [[True if grid[r][c] == 'X' else False for c in range(M)] for r in range(N)]

def read_your_input():
    import sys
    data = sys.stdin.read().split()
    idx = 0
    T = int(data[idx]); idx += 1
    cases = []
    for _ in range(T):
        N, M = int(data[idx]), int(data[idx+1]); idx += 2
        grid = []
        for r in range(N):
            grid.append(data[idx]); idx += 1
        cases.append((N, M, grid))
    return cases