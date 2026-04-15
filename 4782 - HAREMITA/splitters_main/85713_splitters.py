import sys
from math import gcd
input = sys.stdin.readline

def solve(N, M, grid):
    # Track fraction of items reaching each tile as (numerator, denominator)
    # Start at (0,0) with fraction 1/1
    # Use rational arithmetic
    
    # Direction mappings
    dirs = {'>': (0,1), '<': (0,-1), '^': (-1,0), 'v': (1,0)}
    
    # BFS/DFS tracking fraction at each tile
    from fractions import Fraction
    
    frac = {}  # (r,c) -> Fraction
    frac[(0,0)] = Fraction(1)
    
    # Process in order (no cycles guaranteed)
    # Use a queue
    from collections import deque
    queue = deque()
    queue.append((0, 0))
    visited = set()
    visited.add((0,0))
    
    collected = Fraction(0)
    
    while queue:
        r, c = queue.popleft()
        tile = grid[r][c]
        f = frac.get((r,c), Fraction(0))
        
        if tile == 'X':
            # destroyed
            continue
        elif tile in dirs:
            dr, dc = dirs[tile]
            nr, nc = r+dr, c+dc
            # Check if out of bounds
            if nr < 0 or nr >= N or nc < 0 or nc >= M:
                collected += f
            else:
                if (nr, nc) not in frac:
                    frac[(nr,nc)] = Fraction(0)
                frac[(nr,nc)] += f
                if (nr,nc) not in visited:
                    visited.add((nr,nc))
                    queue.append((nr,nc))
        elif tile == 'S':
            # Find valid adjacent tiles
            valid = []
            for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                nr, nc = r+dr, c+dc
                if 0 <= nr < N and 0 <= nc < M:
                    t = grid[nr][nc]
                    if t == 'X':
                        valid.append((nr,nc))
                    elif t in dirs:
                        # Not pointing back at splitter
                        ddr, ddc = dirs[t]
                        if not (nr+ddr == r and nc+ddc == c):
                            valid.append((nr,nc))
            
            share = f / len(valid)
            for (nr,nc) in valid:
                if (nr,nc) not in frac:
                    frac[(nr,nc)] = Fraction(0)
                frac[(nr,nc)] += share
                if (nr,nc) not in visited:
                    visited.add((nr,nc))
                    queue.append((nr,nc))
    
    # Output as irreducible fraction
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