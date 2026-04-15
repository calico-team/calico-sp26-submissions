import math
from fractions import Fraction

def solve(N, M, factory):
    # Directions: up, down, left, right
    dirs = {'^': (-1, 0), 'v': (1, 0), '<': (0, -1), '>': (0, 1)}
    
    # Store probabilities of an item being at a certain tile
    # Since the graph is a DAG (items never enter the same tile twice),
    # we can process tiles in topological order or simply use recursion with memoization.
    memo = {}

    def get_neighbors(r, c):
        res = []
        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M:
                target = factory[nr][nc]
                if target == 'X':
                    res.append((nr, nc))
                elif target in dirs:
                    # Check if conveyor points back at the splitter
                    tr, tc = dirs[target]
                    if nr + tr != r or nc + tc != c:
                        res.append((nr, nc))
            elif nr < 0 or nr >= N or nc < 0 or nc >= M:
                # Moving off the grid is a valid path for splitters
                res.append((nr, nc))
        return res

    def find_prob(r, c):
        if (r, c) in memo:
            return memo[(r, c)]
        
        # Base case: item enters at (0, 0)
        if r == 0 and c == 0:
            return Fraction(1, 1)
        
        # To calculate prob at (r, c), we'd need to know who points here.
        # But since it's a DAG, let's push probabilities forward instead.
        return Fraction(0)

    # Push-based DP because it's a DAG
    probs = {(0, 0): Fraction(1, 1)}
    collected = Fraction(0)
    
    # We use a queue for a topological-like traversal
    # Constraints guarantee no cycles and no re-entry.
    queue = [(0, 0)]
    visited = set()
    
    # Sort tiles to ensure we process them in an order that respects the flow
    # Standard BFS works here because of the "never move into the same tile twice" rule.
    idx = 0
    while idx < len(queue):
        r, c = queue[idx]
        idx += 1
        
        if (r, c) not in probs: continue
        p = probs[(r, c)]
        tile = factory[r][c]
        
        if tile == 'X':
            continue
        elif tile in dirs:
            dr, dc = dirs[tile]
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M:
                probs[(nr, nc)] = probs.get((nr, nc), Fraction(0)) + p
                if (nr, nc) not in visited:
                    visited.add((nr, nc))
                    queue.append((nr, nc))
            else:
                collected += p
        elif tile == 'S':
            neighbors = get_neighbors(r, c)
            if neighbors:
                p_share = p / len(neighbors)
                for nr, nc in neighbors:
                    if 0 <= nr < N and 0 <= nc < M:
                        probs[(nr, nc)] = probs.get((nr, nc), Fraction(0)) + p_share
                        if (nr, nc) not in visited:
                            visited.add((nr, nc))
                            queue.append((nr, nc))
                    else:
                        collected += p_share
                        
    return collected.numerator, collected.denominator

def read_your_input():
    import sys
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    T = int(input_data[0])
    ptr = 1
    for _ in range(T):
        N = int(input_data[ptr])
        M = int(input_data[ptr+1])
        ptr += 2
        factory = input_data[ptr:ptr+N]
        ptr += N
        P, Q = solve(N, M, factory)
        print(f"{P} {Q}")

if __name__ == '__main__':
    read_your_input()