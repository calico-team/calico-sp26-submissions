from fractions import Fraction
from collections import deque
import sys
input = sys.stdin.readline

def solve():
    n, m = map(int, input().split())
    grid = [input().strip() for _ in range(n)]
    
    dir_map = {'^': (-1, 0), 'v': (1, 0), '<': (0, -1), '>': (0, 1)}
    
    frac = [[Fraction(0)] * m for _ in range(n)]
    frac[0][0] = Fraction(1)
    
    collected = Fraction(0)
    visited = [[False] * m for _ in range(n)]
    
    queue = deque()
    queue.append((0, 0))
    visited[0][0] = True
    
    while queue:
        r, c = queue.popleft()
        tile = grid[r][c]
        f = frac[r][c]
        
        if f == 0 or tile == '.' or tile == 'X':
            continue
        
        if tile in dir_map:
            dr, dc = dir_map[tile]
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < m:
                frac[nr][nc] += f
                if not visited[nr][nc]:
                    visited[nr][nc] = True
                    queue.append((nr, nc))
            else:
                collected += f
        
        elif tile == 'S':
            valid = []
            for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < m:
                    adj = grid[nr][nc]
                    if adj == 'X':
                        valid.append((nr, nc))
                    elif adj in dir_map:
                        adr, adc = dir_map[adj]
                        if (nr + adr, nc + adc) != (r, c):
                            valid.append((nr, nc))
            
            share = f / len(valid)
            for nr, nc in valid:
                frac[nr][nc] += share
                if not visited[nr][nc]:
                    visited[nr][nc] = True
                    queue.append((nr, nc))
    
    p = collected.numerator
    q = collected.denominator
    print(p, q)