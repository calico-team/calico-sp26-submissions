import sys
from fractions import Fraction

def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    sys.setrecursionlimit(2000)
    memo = {}
    
    def dfs(r, c):
        # Base Case: If the item falls off the grid, it is collected.
        if r < 0 or r >= N or c < 0 or c >= M:
            return Fraction(1, 1)
        
        # Return memoized result to prevent redundant calculations
        if (r, c) in memo:
            return memo[(r, c)]
        
        char = factory[r][c]
        ans = Fraction(0, 1)
        
        if char == 'X':
            ans = Fraction(0, 1)
        elif char == '<':
            ans = dfs(r, c - 1)
        elif char == '>':
            ans = dfs(r, c + 1)
        elif char == '^':
            ans = dfs(r - 1, c)
        elif char == 'v':
            ans = dfs(r + 1, c)
        elif char == 'S':
            valid_neighbors = []
            
            # Check UP: Valid if it's 'X' or a conveyor not pointing DOWN ('v')
            if r - 1 >= 0 and factory[r - 1][c] in 'X<>^':
                valid_neighbors.append((r - 1, c))
            # Check DOWN: Valid if it's 'X' or a conveyor not pointing UP ('^')
            if r + 1 < N and factory[r + 1][c] in 'X<>v':
                valid_neighbors.append((r + 1, c))
            # Check LEFT: Valid if it's 'X' or a conveyor not pointing RIGHT ('>')
            if c - 1 >= 0 and factory[r][c - 1] in 'X<^v':
                valid_neighbors.append((r, c - 1))
            # Check RIGHT: Valid if it's 'X' or a conveyor not pointing LEFT ('<')
            if c + 1 < M and factory[r][c + 1] in 'X>^v':
                valid_neighbors.append((r, c + 1))
                
            # Splitter divides incoming items evenly among valid neighbors
            k = len(valid_neighbors)
            if k > 0:
                for nr, nc in valid_neighbors:
                    ans += dfs(nr, nc) / k
        
        memo[(r, c)] = ans
        return ans

    # All items that enter the factory start on the top left tile
    result = dfs(0, 0)
    return result.numerator, result.denominator


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()