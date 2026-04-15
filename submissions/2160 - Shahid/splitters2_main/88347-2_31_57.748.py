
import sys

def solve() -> None:
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    T = int(next(it))
    out_lines = []

    for _ in range(T):
        P = int(next(it))
        A = int(next(it))
        B = int(next(it))

        n = A + B                      # number of splitters
        bases = [2] * A + [3] * B      # sequence of splitter types

        # mixed‑radix digits of P in the given base order
        digits = [0] * n
        rem = P
        for i in range(n - 1, -1, -1):
            digits[i] = rem % bases[i]
            rem //= bases[i]

        rows = 2 * n + 1               # enough room for all splitters + start
        cols = 3
        grid = [['.' for _ in range(cols)] for __ in range(rows)]

        # starting point (top‑left)
        grid[0][0] = '>'
        grid[0][1] = 'v'

        for i in range(n):
            r = 2 * i + 1             # row of the i‑th splitter
            c = 1                     # column of splitters
            grid[r][c] = 'S'

            # left output (column 0)
            if bases[i] == 2:         # binary splitter
                if digits[i] == 1:
                    grid[r][0] = '<'   # collector
                else:
                    grid[r][0] = 'X'   # destroy
            else:                     # ternary splitter
                if digits[i] >= 1:
                    grid[r][0] = '<'
                else:
                    grid[r][0] = 'X'
                # right output (column 2)
                if digits[i] >= 2:
                    grid[r][2] = '>'
                else:
                    grid[r][2] = 'X'

            # down output
            if i < n - 1:
                grid[r + 1][1] = 'v'   # go to next splitter
            else:
                grid[r + 1][1] = 'X'   # last splitter: destroy

        out_lines.append(f"{rows} {cols}")
        for row in grid:
            out_lines.append(''.join(row))

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()
