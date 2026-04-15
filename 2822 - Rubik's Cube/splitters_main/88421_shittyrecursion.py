import sys
import fractions
import functools

sys.setrecursionlimit(2000)

def tang():
    params = list(map(int, input().split()))
    grid = []
    for i in range(params[0]):
        grid.append(input().strip())
    @functools.lru_cache(None)
    
    def dfs(r, c):
        if r < 0 or r >= params[0] or c < 0 or c >= params[1]:
            return fractions.Fraction(1, 1)
        t = grid[r][c]
        if t == 'X' or t == '.':
            return fractions.Fraction(0, 1)
        elif t == '>':
            return dfs(r, c + 1)
        elif t == '<':
            return dfs(r, c - 1)
        elif t == 'v':
            return dfs(r + 1, c)
        elif t == '^':
            return dfs(r - 1, c)
        elif t == 'S':
            valid = []
            if c + 1 < params[1]:
                nt = grid[r][c+1]
                if nt == 'X' or (nt in '<>^v' and nt != '<'):
                    valid.append((r, c+1))
            if c - 1 >= 0:
                nt = grid[r][c-1]
                if nt == 'X' or (nt in '<>^v' and nt != '>'):
                    valid.append((r, c-1))
            if r + 1 < params[0]:
                nt = grid[r+1][c]
                if nt == 'X' or (nt in '<>^v' and nt != '^'):
                    valid.append((r+1, c))
            if r - 1 >= 0:
                nt = grid[r-1][c]
                if nt == 'X' or (nt in '<>^v' and nt != 'v'):
                    valid.append((r-1, c))
                    
            if not valid:
                return fractions.Fraction(0, 1)
                
            res = fractions.Fraction(0, 1)
            for nr, nc in valid:
                res += dfs(nr, nc)
            return res / len(valid)
            
    ans = dfs(0, 0)
    print(f'{ans.numerator} {ans.denominator}')

lines = int(input().strip())
for i in range(lines):
    tang()