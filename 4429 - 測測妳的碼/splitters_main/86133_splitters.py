import sys
from fractions import Fraction
from functools import lru_cache

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    t = int(data[0])
    idx = 1
    for _ in range(t):
        n = int(data[idx])
        m = int(data[idx + 1])
        idx += 2
        grid = []
        for _ in range(n):
            grid.append(data[idx])
            idx += 1

        @lru_cache(None)
        def dfs(r, c):
            if r < 0 or r >= n or c < 0 or c >= m:
                return Fraction(1, 1)
            char = grid[r][c]
            if char in 'XxΧ':
                return Fraction(0, 1)
            if char == '<': return dfs(r, c - 1)
            if char == '>': return dfs(r, c + 1)
            if char == '^': return dfs(r - 1, c)
            if char == 'v': return dfs(r + 1, c)

            if char == 'S' or char == 's':
                valid_probs = []
                if r > 0 and grid[r - 1][c] in 'XxΧ<>^v' and grid[r - 1][c] != 'v':
                    valid_probs.append(dfs(r - 1, c))
                if r < n - 1 and grid[r + 1][c] in 'XxΧ<>^v' and grid[r + 1][c] != '^':
                    valid_probs.append(dfs(r + 1, c))
                if c > 0 and grid[r][c - 1] in 'XxΧ<>^v' and grid[r][c - 1] != '>':
                    valid_probs.append(dfs(r, c - 1))
                if c < m - 1 and grid[r][c + 1] in 'XxΧ<>^v' and grid[r][c + 1] != '<':
                    valid_probs.append(dfs(r, c + 1))
                if valid_probs:
                    return sum(valid_probs, Fraction(0, 1)) / len(valid_probs)
            return Fraction(0, 1)

        ans = dfs(0, 0)
        print(f"{ans.numerator} {ans.denominator}")

if __name__ == '__main__':
    sys.setrecursionlimit(2000)
    solve()