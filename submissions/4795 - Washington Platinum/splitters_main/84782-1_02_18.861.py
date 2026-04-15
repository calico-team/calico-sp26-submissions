import sys
from fractions import Fraction # the goat

sys.setrecursionlimit(2000) # do we need higher?? idk 

def oeuoiweuoiweuiowqoiwq():
    inp = sys.stdin.read().split()
    
    T = int(inp[0])
    idx = 1
    
    for _ in range(T):
        if idx >= len(inp):
            break
        
        N = int(inp[idx])
        M = int(inp[idx+1])
        idx += 2
        
        grid = []
        for _ in range(N):
            grid.append(inp[idx])
            idx += 1
            
        memo = {}
        
        def dfs(r, c):
            if r < 0 or r >= N or c < 0 or c >= M:
                return Fraction(1, 1)
            if (r, c) in memo:
                return memo[(r, c)]
            
            char = grid[r][c]
            
            if char == 'X':
                ans = Fraction(0, 1)
                
            elif char in ['<', '>', '^', 'v']:
                nr, nc = r, c
                if char == '<': nc -= 1
                elif char == '>': nc += 1
                elif char == '^': nr -= 1
                elif char == 'v': nr += 1
                ans = dfs(nr, nc)
                
            elif char == 'S':
                goodneigh = []
                
                for dr, dc, opp in [(-1, 0, 'v'), (1, 0, '^'), (0, -1, '>'), (0, 1, '<')]:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < N and 0 <= nc < M:
                        nchar = grid[nr][nc]
                        if nchar == 'X' or (nchar in ['<', '>', '^', 'v'] and nchar != opp):
                            goodneigh.append((nr, nc))
                
                ans = Fraction(0, 1)
                if goodneigh:
                    prob = Fraction(1, len(goodneigh))
                    for nr, nc in goodneigh:
                        ans += prob * dfs(nr, nc)
            else:
                ans = Fraction(0, 1)
                
            memo[(r, c)] = ans
            return ans

        res = dfs(0, 0)
        print(f"{res.numerator} {res.denominator}")

if __name__ == '__main__':
    oeuoiweuoiweuiowqoiwq()