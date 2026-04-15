import sys
from fractions import Fraction

# Increase recursion depth for complex conveyor paths
sys.setrecursionlimit(5000)

def solve(N, M, factory):
    memo = {}

    def get_prob(r, c):
        # Items are successfully collected if moved OUT of the grid by a conveyor
        if not (0 <= r < N and 0 <= c < M):
            return Fraction(1, 1)

        if (r, c) in memo:
            return memo[(r, c)]

        tile = factory[r][c]
        
        # Destroy tiles: Support both English 'X' and Greek '\u03a7' found in some problem sets
        if tile in ('X', 'x', '\u03a7', '\u03c7'):
            res = Fraction(0, 1)
        
        # Conveyor tiles: Move to the adjacent tile
        elif tile in ('^', 'v', 'V', '<', '>'):
            # Normalize 'v' for logic
            norm_char = 'V' if tile.lower() == 'v' else tile
            dr, dc = {'^': (-1, 0), 'V': (1, 0), '<': (0, -1), '>': (0, 1)}[norm_char]
            res = get_prob(r + dr, c + dc)
            
        # Splitter tiles: Evenly distribute to VALID neighbors
        elif tile.upper() == 'S':
            valid_neighbors = []
            # Checks: (row_delta, col_delta, direction_that_points_back)
            checks = [
                (-1, 0, ('v', 'V')), # Neighbor is UP: points back if it's Down
                (1, 0, ('^')),       # Neighbor is DOWN: points back if it's Up
                (0, -1, ('>')),      # Neighbor is LEFT: points back if it's Right
                (0, 1, ('<'))        # Neighbor is RIGHT: points back if it's Left
            ]
            
            for dr, dc, back_chars in checks:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < M:
                    neighbor_tile = factory[nr][nc]
                    # Valid if it's a destroy tile
                    if neighbor_tile in ('X', 'x', '\u03a7', '\u03c7'):
                        valid_neighbors.append((nr, nc))
                    # Valid if it's a conveyor NOT pointing back at the splitter
                    elif neighbor_tile in ('^', 'v', 'V', '<', '>') and neighbor_tile not in back_chars:
                        valid_neighbors.append((nr, nc))
            
            if not valid_neighbors:
                res = Fraction(0, 1)
            else:
                # Average the probabilities of all valid exit paths
                total = sum(get_prob(nr, nc) for nr, nc in valid_neighbors)
                res = total / len(valid_neighbors)
        
        # Empty tiles (.) or other characters
        else:
            res = Fraction(0, 1)

        memo[(r, c)] = res
        return res

    # All items enter at the top-left (0, 0)
    ans = get_prob(0, 0)
    return ans.numerator, ans.denominator

def main():
    try:
        # Read total test cases
        line = input().strip()
        if not line: return
        T_cases = int(line)
        
        for _ in range(T_cases):
            # Read N and M, skipping any potential empty lines
            dims = input().split()
            while not dims:
                dims = input().split()
            
            N, M = int(dims[0]), int(dims[1])
            
            # Read the grid
            factory = []
            for _ in range(N):
                factory.append(input().rstrip('\r\n'))
                
            P, Q = solve(N, M, factory)
            print(f"{P} {Q}")
            
    except EOFError:
        pass
    except ValueError:
        pass

if __name__ == '__main__':
    main()