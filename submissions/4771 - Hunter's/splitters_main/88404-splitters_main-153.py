from fractions import Fraction
from math import gcd
from collections import deque

def solve():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        grid = [input().strip() for _ in range(N)]
        
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        dir_char = {'^': 0, 'v': 1, '<': 2, '>': 3}
        opp = {0: 1, 1: 0, 2: 3, 3: 2}
        
        graph = [[[] for _ in range(M)] for _ in range(N)]
        indeg = [[0] * M for _ in range(N)]
        
        for r in range(N):
            for c in range(M):
                ch = grid[r][c]
                if ch == '.' or ch == 'X':
                    continue
                if ch in '<>^v':
                    dr, dc = dirs[dir_char[ch]]
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < N and 0 <= nc < M:
                        graph[r][c].append((nr, nc, Fraction(1, 1)))
                        indeg[nr][nc] += 1
                elif ch == 's':
                    valid = []
                    for d_idx, (dr, dc) in enumerate(dirs):
                        nr, nc = r + dr, c + dc
                        if 0 <= nr < N and 0 <= nc < M:
                            nch = grid[nr][nc]
                            if nch == '.':
                                continue
                            if nch == 'X':
                                valid.append((nr, nc))
                            elif nch in '<>^v':
                                nd = dir_char[nch]
                                if nd != opp[d_idx]:
                                    valid.append((nr, nc))
                    k = len(valid)
                    if k > 0:
                        for nr, nc in valid:
                            graph[r][c].append((nr, nc, Fraction(1, k)))
                            indeg[nr][nc] += 1
        
        frac = [[Fraction(0, 1) for _ in range(M)] for _ in range(N)]
        frac[0][0] = Fraction(1, 1)
        
        q = deque()
        q.append((0, 0))
        
        while q:
            r, c = q.popleft()
            for nr, nc, prob in graph[r][c]:
                frac[nr][nc] += frac[r][c] * prob
                indeg[nr][nc] -= 1
                if indeg[nr][nc] == 0:
                    q.append((nr, nc))
        
        collected = Fraction(0, 1)
        destroyed = Fraction(0, 1)
        
        for r in range(N):
            for c in range(M):
                ch = grid[r][c]
                if ch == 'X':
                    destroyed += frac[r][c]
                elif ch in '<>^v':
                    dr, dc = dirs[dir_char[ch]]
                    nr, nc = r + dr, c + dc
                    if nr < 0 or nr >= N or nc < 0 or nc >= M:
                        collected += frac[r][c]
        
        if collected == 0:
            print("0 1")
        else:
            p = collected.numerator
            q = collected.denominator
            g = gcd(p, q)
            print(f"{p//g} {q//g}")

if __name__ == "__main__":
    solve()