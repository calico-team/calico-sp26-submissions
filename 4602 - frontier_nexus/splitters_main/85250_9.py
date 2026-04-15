from fractions import Fraction
from sys import setrecursionlimit
setrecursionlimit(10**6)

def solve():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        grid = [list(input().strip()) for _ in range(N)]
        
        # Directions: up, down, left, right
        dirs = [(-1,0), (1,0), (0,-1), (0,1)]
        dir_char = ['^', 'v', '<', '>']
        opposite = {'^':'v', 'v':'^', '<':'>', '>':'<'}
        
        prob = [[Fraction(0) for _ in range(M)] for _ in range(N)]
        prob[0][0] = Fraction(1)
        
        # We need to propagate in topological order. Use recursion with visited.
        visited = [[False for _ in range(M)] for _ in range(N)]
        
        def get_valid_neighbors_for_splitter(r, c):
            neighbors = []
            for dr, dc, ch in zip([-1,1,0,0], [0,0,-1,1], ['^','v','<','>']):
                nr, nc = r+dr, c+dc
                if nr < 0 or nr >= N or nc < 0 or nc >= M:
                    continue
                if grid[nr][nc] == '×':  # destroy tile
                    neighbors.append((nr, nc))
                elif grid[nr][nc] in '<>^v':  # conveyor
                    # Check if conveyor points back to splitter
                    if grid[nr][nc] != opposite[ch]:  # not pointing back
                        neighbors.append((nr, nc))
            return neighbors
        
        collected = Fraction(0)
        
        def dfs(r, c):
            nonlocal collected
            if visited[r][c]:
                return
            visited[r][c] = True
            p = prob[r][c]
            if p == 0:
                return
            
            tile = grid[r][c]
            
            if tile == '×':  # destroy tile
                # fraction p is destroyed, nothing to propagate
                return
            
            if tile in '<>^v':  # conveyor
                # Move to next tile
                dr, dc = 0, 0
                if tile == '^':
                    dr, dc = -1, 0
                elif tile == 'v':
                    dr, dc = 1, 0
                elif tile == '<':
                    dr, dc = 0, -1
                elif tile == '>':
                    dr, dc = 0, 1
                nr, nc = r+dr, c+dc
                if nr < 0 or nr >= N or nc < 0 or nc >= M:
                    # Collected
                    collected += p
                else:
                    prob[nr][nc] += p
                    dfs(nr, nc)
                return
            
            if tile == 's':  # splitter
                neighbors = get_valid_neighbors_for_splitter(r, c)
                if not neighbors:
                    return  # no valid output, fraction lost? Problem says at least 2 valid.
                share = p / len(neighbors)
                for nr, nc in neighbors:
                    prob[nr][nc] += share
                    dfs(nr, nc)
                return
        
        dfs(0, 0)
        
        # Output as irreducible fraction
        p = collected.numerator
        q = collected.denominator
        print(p, q)

if __name__ == "__main__":
    solve()