from fractions import Fraction
from math import gcd
from collections import deque
import sys
input = sys.stdin.readline

DIRECTIONS = {
    '>': (0, 1),
    '<': (0, -1),
    '^': (-1, 0),
    'v': (1, 0)
}

def get_splitter_outputs(grid, row, col):
    """
    A splitter sends items to all neighbors except:
    - Empty tiles
    - Conveyor tiles that point back at the splitter
    """
    valid = []
    for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        nr, nc = row + dr, col + dc

        # Must be within bounds
        if not (0 <= nr < len(grid) and 0 <= nc < len(grid[0])):
            continue

        neighbor = grid[nr][nc]

        # Destroy tiles always accept items
        if neighbor == 'X':
            valid.append((nr, nc))

        # Conveyor tiles are valid only if they don't point back at us
        elif neighbor in DIRECTIONS:
            points_to_row = nr + DIRECTIONS[neighbor][0]
            points_to_col = nc + DIRECTIONS[neighbor][1]
            points_back = (points_to_row == row and points_to_col == col)
            if not points_back:
                valid.append((nr, nc))

    return valid


def simulate(grid):
    rows, cols = len(grid), len(grid[0])
    collected = Fraction(0)

    # Start all items (fraction = 1) at the top-left tile
    queue = deque([(0, 0, Fraction(1))])

    while queue:
        r, c, amount = queue.popleft()
        tile = grid[r][c]

        if tile == 'X':
            # Items are destroyed here, nothing to do
            continue

        elif tile in DIRECTIONS:
            dr, dc = DIRECTIONS[tile]
            nr, nc = r + dr, c + dc

            if 0 <= nr < rows and 0 <= nc < cols:
                # Move items to the next tile
                queue.append((nr, nc, amount))
            else:
                # Conveyor points outside the grid — items are collected!
                collected += amount

        elif tile == 'S':
            targets = get_splitter_outputs(grid, r, c)

            # Divide items equally among all valid outputs
            share = amount / len(targets)
            for nr, nc in targets:
                queue.append((nr, nc, share))

    return collected


def format_fraction(f):
    p, q = f.numerator, f.denominator
    if p == 0:
        return "0 1"
    g = gcd(p, q)
    return f"{p // g} {q // g}"


def main():
    T = int(input())
    for _ in range(T):
        n, m = map(int, input().split())
        grid = [input().strip() for _ in range(n)]
        result = simulate(grid)
        print(format_fraction(result))


main()