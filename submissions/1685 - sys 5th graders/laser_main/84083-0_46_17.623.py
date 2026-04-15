import sys

input = sys.stdin.read
data = input().split()

T = int(data[0])
index = 1

for _ in range(T):
    P = int(data[index])
    A = int(data[index + 1])
    B = int(data[index + 2])
    index += 3

    L = A + B
    r = [2] * A + [3] * B
    N = 3
    M = 2 * L + 2

    grid = [['.' for _ in range(M)] for _ in range(N)]

    for c in range(2 * L + 1):
        if c % 2 == 0:
            grid[1][c] = '>'
        else:
            grid[1][c] = 's'
    grid[1][2 * L + 1] = 'x'

    grid[0][0] = 'v'

    digits = [0] * L
    current = P
    for i in range(L - 1, -1, -1):
        ri = r[i]
        digits[i] = current % ri
        current //= ri


    for k in range(L):
        s_col = 2 * k + 1
        dk = digits[k]
        rk = r[k]
        if rk == 2:
            drow = 2
            dcol = s_col
            if dk == 1:
                grid[drow][dcol] = 'v'
            else:
                grid[drow][dcol] = 'x'
        else:
            urow = 0
            ucol = s_col
            if dk >= 1:
                grid[urow][ucol] = '^'
            else:
                grid[urow][ucol] = 'x'
            # down
            drow = 2
            dcol = s_col
            if dk >= 2:
                grid[drow][dcol] = 'v'
            else:
                grid[drow][dcol] = 'x'

    print(N, M)
    for row in grid:
        print(''.join(row))