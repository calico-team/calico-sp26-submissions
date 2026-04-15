import sys
from fractions import Fraction

# Increase recursion depth to safely accommodate paths up to 15x15
sys.setrecursionlimit(2000)

def solve():
    # Read all tokens from standard input
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    idx = 1
    
    out = []
    for _ in range(T):
        N = int(input_data[idx])
        M = int(input_data[idx+1])
        idx += 2
        
        grid = []
        for _ in range(N):
            grid.append(input_data[idx])
            idx += 1
            
        # Dictionary to store the computed probabilities for each tile
        memo = {}
        
        def get_prob(r, c):
            # Base Case 1: Conveyor pushed the item out of the grid (Collected)
            if r < 0 or r >= N or c < 0 or c >= M:
                return Fraction(1, 1)
            
            if (r, c) in memo:
                return memo[(r, c)]
            
            ch = grid[r][c].lower()
            
            # Base Case 2: Item hit a destroy tile
            if ch == 'x':
                memo[(r, c)] = Fraction(0, 1)
                return memo[(r, c)]
                
            # Conveyor Belt: Passes item strictly to the next directed tile
            if ch in '^v<>':
                nr, nc = r, c
                if ch == '^': nr -= 1
                elif ch == 'v': nr += 1
                elif ch == '<': nc -= 1
                elif ch == '>': nc += 1
                
                ans = get_prob(nr, nc)
                memo[(r, c)] = ans
                return ans
                
            # Splitter: Distributes item evenly to valid adjacent tiles
            if ch == 's':
                valid = []
                
                # Check Up
                if r - 1 >= 0:
                    n_ch = grid[r-1][c].lower()
                    if n_ch == 'x' or (n_ch in '^v<>' and n_ch != 'v'):
                        valid.append((r-1, c))
                # Check Down
                if r + 1 < N:
                    n_ch = grid[r+1][c].lower()
                    if n_ch == 'x' or (n_ch in '^v<>' and n_ch != '^'):
                        valid.append((r+1, c))
                # Check Left
                if c - 1 >= 0:
                    n_ch = grid[r][c-1].lower()
                    if n_ch == 'x' or (n_ch in '^v<>' and n_ch != '>'):
                        valid.append((r, c-1))
                # Check Right
                if c + 1 < M:
                    n_ch = grid[r][c+1].lower()
                    if n_ch == 'x' or (n_ch in '^v<>' and n_ch != '<'):
                        valid.append((r, c+1))
                
                if not valid:
                    ans = Fraction(0, 1)
                else:
                    ans = sum(get_prob(nr, nc) for nr, nc in valid) / len(valid)
                    
                memo[(r, c)] = ans
                return ans
                
            # Fallback for empty spaces (unreachable by problem definition)
            return Fraction(0, 1)
        
        # All items start at the top-left tile (0, 0)
        res = get_prob(0, 0)
        out.append(f"{res.numerator} {res.denominator}")
        
    print('\n'.join(out))

if __name__ == '__main__':
    solve()