import sys
input = sys.stdin.readline


def solve():
    P, A, B = map(int, input().split())

    # We will build the factory step by step from left to right.
    # Each step adds a splitter that divides the flow.

    grid = [["."]]   # start with a single cell
    current_col = 0

    # Make sure every row has enough columns
    def expand_columns(col_needed):
        for row in grid:
            while len(row) <= col_needed:
                row.append('.')

    # Make sure we have at least 3 rows
    def ensure_three_rows():
        while len(grid) < 3:
            grid.append(['.'] * len(grid[0]))

    # ----------- Handle 3-way splitters (for 3^B) -----------
    for _ in range(B):
        ensure_three_rows()
        expand_columns(current_col + 2)

        # Layout of 3-split:
        #   v
        # > S >
        #   v
        grid[1][current_col] = '>'
        grid[1][current_col + 1] = 'S'

        grid[0][current_col + 1] = 'v'
        grid[2][current_col + 1] = 'v'

        current_col += 2

    # ----------- Handle 2-way splitters (for 2^A) -----------
    for _ in range(A):
        ensure_three_rows()
        expand_columns(current_col + 2)

        # Layout of 2-split:
        # > S >
        #   v
        grid[1][current_col] = '>'
        grid[1][current_col + 1] = 'S'
        grid[2][current_col + 1] = 'v'

        current_col += 2

    # ----------- Final exit -----------
    expand_columns(current_col)

    # Send remaining flow to the right (collected)
    grid[1][current_col] = '>'

    # Output result
    rows = len(grid)
    cols = len(grid[0])

    print(rows, cols)
    for row in grid:
        print(''.join(row))


def main():
    t = int(input())
    for _ in range(t):
        solve()


def read_your_input():
    return map(int, input().split())


main()