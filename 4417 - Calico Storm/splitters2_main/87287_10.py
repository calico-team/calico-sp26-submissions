import sys
input = sys.stdin.readline


def solve():
    P, A, B = map(int, input().split())

    decisions = []
    remaining = P

    for j in range(B):
        slot_value = (2 ** A) * (3 ** (B - j - 1))
        take = min(2, remaining // slot_value)
        decisions.append(('3', take))
        remaining -= take * slot_value

    for j in range(A):
        slot_value = 2 ** (A - j - 1)
        take = min(1, remaining // slot_value)
        decisions.append(('2', take))
        remaining -= take * slot_value

    final_collect = remaining

    N = 3
    M = 2 * (A + B) + 1
    grid = [['.' for _ in range(M)] for _ in range(N)]

    for k, (split_type, take) in enumerate(decisions):
        approach_col = 2 * k
        splitter_col = 2 * k + 1

        if k == 0:
            grid[0][approach_col] = 'v'
        grid[1][approach_col] = '>'
        grid[1][splitter_col] = 'S'

        if split_type == '2':
            grid[0][splitter_col] = '.'
            grid[2][splitter_col] = 'v' if take == 1 else 'X'
        else:
            if take == 0:
                grid[0][splitter_col] = 'X'
                grid[2][splitter_col] = 'X'
            elif take == 1:
                grid[0][splitter_col] = 'X'
                grid[2][splitter_col] = 'v'
            else:
                grid[0][splitter_col] = '^'
                grid[2][splitter_col] = 'v'

    terminal_col = M - 1
    grid[1][terminal_col] = '>' if final_collect == 1 else 'X'

    print(N, M)
    for row in grid:
        print(''.join(row))


def main():
    T = int(input())
    for _ in range(T):
        solve()


main()