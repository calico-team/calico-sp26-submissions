import sys
from fractions import Fraction
from collections import deque

def solve():
    line = sys.stdin.readline().split()
    if not line: return
    n, m = map(int, line)
    
    grid = [sys.stdin.readline().strip() for _ in range(n)]
    
    probs = [[Fraction(0) for _ in range(m)] for _ in range(n)]
    probs[0][0] = Fraction(1)
    
    in_degree = [[0 for _ in range(m)] for _ in range(n)]
    dirs = {'^': (-1, 0), 'v': (1, 0), '<': (0, -1), '>': (0, 1)}
    adj_offsets = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    for r in range(n):
        for c in range(m):
            char = grid[r][c]
            if char in dirs:
                dr, dc = dirs[char]
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < m:
                    in_degree[nr][nc] += 1
            elif char == 's':
                for dr, dc in adj_offsets:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < n and 0 <= nc < m:
                        n_char = grid[nr][nc]
                        if n_char == 'x' or (n_char in dirs and not (nr + dirs[n_char][0] == r and nc + dirs[n_char][1] == c)):
                            in_degree[nr][nc] += 1

    
    queue = deque()
    queue.append((0, 0))
    collected_prob = Fraction(0)

    while queue:
        r, c = queue.popleft()
        char = grid[r][c]
        p = probs[r][c]
        if p == 0: continue

        if char in dirs:
            dr, dc = dirs[char]
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < m:
                probs[nr][nc] += p
                in_degree[nr][nc] -= 1
                if in_degree[nr][nc] == 0:
                    queue.append((nr, nc))
            else:
                collected_prob += p
        
        elif char == 's':
            valid_targets = []
            for dr, dc in adj_offsets:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < m:
                    n_char = grid[nr][nc]
                    if n_char == 'x' or (n_char in dirs and not (nr + dirs[n_char][0] == r and nc + dirs[n_char][1] == c)):
                        valid_targets.append((nr, nc))
            
            if valid_targets:
                split_p = p / len(valid_targets)
                for nr, nc in valid_targets:
                    probs[nr][nc] += split_p
                    in_degree[nr][nc] -= 1
                    if in_degree[nr][nc] == 0:
                        queue.append((nr, nc))
    print(f"{collected_prob.numerator} {collected_prob.denominator}")

def main():
    line = sys.stdin.readline()
    if line:
        t_str = line.strip()
        if t_str:
            t = int(t_str)
            for _ in range(t):
                solve()

if __name__ == "__main__":
    main()