import sys

def solve() -> None:
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    t = int(next(it))
    out_lines = []
    for _ in range(t):
        P = int(next(it))
        A = int(next(it))
        B = int(next(it))
        total_den = 1
        for _ in range(A):
            total_den *= 2
        for _ in range(B):
            total_den *= 3
        cur_num = P
        cur_den = total_den
        a_rem = A
        b_rem = B
        ops = []
        for _ in range(A + B):
            if a_rem > 0:
                d = 2
                a_rem -= 1
            else:
                d = 3
                b_rem -= 1
            new_den = cur_den // d
            digit = cur_num // new_den
            cur_num %= new_den
            cur_den = new_den
            ops.append((d, digit))
        S = len(ops)
        N, M = 3, 2 * S + 1
        grid = [['.' for _ in range(M)] for __ in range(N)]
        grid[0][0] = 'v'
        grid[1][0] = '>'
        for i, (d, digit) in enumerate(ops):
            col = 1 + 2 * i
            grid[1][col] = 's'
            is_last = (i == S - 1)
            if d == 2:
                if is_last:
                    if digit == 1:
                        grid[0][col] = '^'
                        grid[2][col] = 'x'
                    else:
                        grid[0][col] = 'x'
                        grid[2][col] = 'x'
                else:
                    grid[1][col+1] = '>'
                    if digit == 1:
                        grid[0][col] = '^'
                    else:
                        grid[0][col] = 'x'
            else:
                if is_last:
                    grid[1][col+1] = 'x'
                    if digit >= 1:
                        grid[0][col] = '^'
                    else:
                        grid[0][col] = 'x'
                    if digit >= 2:
                        grid[2][col] = 'v'
                    else:
                        grid[2][col] = 'x'
                else:
                    grid[1][col+1] = '>'
                    if digit >= 1:
                        grid[0][col] = '^'
                    else:
                        grid[0][col] = 'x'
                    if digit >= 2:
                        grid[2][col] = 'v'
                    else:
                        grid[2][col] = 'x'
        out_lines.append(f"{N} {M}")
        for r in range(N):
            out_lines.append(''.join(grid[r]))
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()
