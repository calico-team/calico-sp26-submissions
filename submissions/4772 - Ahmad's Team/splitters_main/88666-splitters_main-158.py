from fractions import Fraction
import sys

# Increase recursion depth to handle long, winding conveyor paths
sys.setrecursionlimit(2000)

def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    memo = {}

    def get_prob(r, c):
        # If the item falls off the edge, it means it is collected 
        if not (0 <= r < N and 0 <= c < M):
            return Fraction(1, 1)

        # Return memoized probability to prevent redundant calculations
        if (r, c) in memo:
            return memo[(r, c)]

        # Handle both lower and upper case variations from sample inputs
        char = factory[r][c].upper() if factory[r][c].isalpha() else factory[r][c]

        if char == 'X':
            ans = Fraction(0, 1)
        elif char in '^v<>':
            nr, nc = r, c
            if char == '^': nr -= 1
            elif char == 'v': nr += 1
            elif char == '<': nc -= 1
            elif char == '>': nc += 1
            ans = get_prob(nr, nc)
        elif char == 'S':
            valid_neighbors = []
            
            # Check UP neighbor 
            if r - 1 >= 0:
                n_char = factory[r-1][c].upper() if factory[r-1][c].isalpha() else factory[r-1][c]
                if n_char == 'X' or (n_char in '^v<>' and n_char != 'v'):
                    valid_neighbors.append((r-1, c))
            # Check DOWN neighbor
            if r + 1 < N:
                n_char = factory[r+1][c].upper() if factory[r+1][c].isalpha() else factory[r+1][c]
                if n_char == 'X' or (n_char in '^v<>' and n_char != '^'):
                    valid_neighbors.append((r+1, c))
            # Check LEFT neighbor
            if c - 1 >= 0:
                n_char = factory[r][c-1].upper() if factory[r][c-1].isalpha() else factory[r][c-1]
                if n_char == 'X' or (n_char in '^v<>' and n_char != '>'):
                    valid_neighbors.append((r, c-1))
            # Check RIGHT neighbor
            if c + 1 < M:
                n_char = factory[r][c+1].upper() if factory[r][c+1].isalpha() else factory[r][c+1]
                if n_char == 'X' or (n_char in '^v<>' and n_char != '<'):
                    valid_neighbors.append((r, c+1))

            # Distribute probability evenly among valid neighbors 
            if not valid_neighbors:
                ans = Fraction(0, 1)
            else:
                ans = sum([get_prob(nr, nc) for nr, nc in valid_neighbors], Fraction(0, 1)) / len(valid_neighbors)
        else:
            ans = Fraction(0, 1)

        memo[(r, c)] = ans
        return ans

    # All items enter at the top-left 
    result = get_prob(0, 0)
    
    # Fraction automatically simplifies into irreducible components
    return result.numerator, result.denominator


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input().strip() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()