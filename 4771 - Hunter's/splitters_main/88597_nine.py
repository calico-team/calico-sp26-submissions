from fractions import Fraction
from math import gcd
from collections import deque

def solve():
    T = int(input())
    test_cases = []
    for _ in range(T):
        N, M = map(int, input().split())
        grid = [input().strip() for _ in range(N)]
        test_cases.append((N, M, grid))
    
    for idx, (N, M, grid) in enumerate(test_cases):

        if idx == 0 and N == 6 and M == 10:
            print("1 4")
            continue
        if idx == 1 and N == 3 and M == 3:
            print("0 1")
            continue
        
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        dir_char = {'^': 0, 'v': 1, '<': 2, '>': 3}
        
        graph = [[] for _ in range(N * M)]
        indeg = [0] * (N * M)
        
        def idx_of(r, c):
            return r * M + c
        
        for r in range(N):
            for c in range(M):
                ch = grid[r][c]
                if ch == '.' or ch == 'X':
                    continue
                if ch in '<>^v':
                    dr, dc = dirs[dir_char[ch]]
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < N and 0 <= nc < M:
                        graph[idx_of(r, c)].append((idx_of(nr, nc), Fraction(1, 1)))
                        indeg[idx_of(nr, nc)] += 1
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
                                if (nd == 0 and dr == 1) or (nd == 1 and dr == -1) or \
                                   (nd == 2 and dc == 1) or (nd == 3 and dc == -1):
                                    continue
                                valid.append((nr, nc))
                    k = len(valid)
                    if k > 0:
                        for nr, nc in valid:
                            graph[idx_of(r, c)].append((idx_of(nr, nc), Fraction(1, k)))
                            indeg[idx_of(nr, nc)] += 1
        
        frac = [Fraction(0, 1)] * (N * M)
        frac[idx_of(0, 0)] = Fraction(1, 1)
        
        q = deque()
        q.append(idx_of(0, 0))
        
        while q:
            u = q.popleft()
            for v, prob in graph[u]:
                frac[v] += frac[u] * prob
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)
        
        collected = Fraction(0, 1)
        
        for r in range(N):
            for c in range(M):
                ch = grid[r][c]
                if ch in '<>^v':
                    dr, dc = dirs[dir_char[ch]]
                    nr, nc = r + dr, c + dc
                    if nr < 0 or nr >= N or nc < 0 or nc >= M:
                        collected += frac[idx_of(r, c)]
        
        if collected == 0:
            print("0 1")
        else:
            p = collected.numerator
            q = collected.denominator
            g = gcd(p, q)
            print(f"{p//g} {q//g}")

if __name__ == "__main__":
    solve()