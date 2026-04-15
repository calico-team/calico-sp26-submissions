def solve(P, A, B):
    radices = [2] * A + [3] * B
    n = len(radices)
    temp = P
    rev_digits = []
    for r in reversed(radices):
        rev_digits.append(temp % r)
        temp //= r
    digits = list(reversed(rev_digits))
    rows = 3
    width = 2 * n + 3
    grid = [['.' for _ in range(width)] for __ in range(rows)]
    grid[0][0] = 'v'
    grid[1][0] = '>'
    for c in range(1, 2):
        grid[1][c] = '>'
    for i, (r, d) in enumerate(zip(radices, digits)):
        col = 2 + 2 * i
        grid[1][col] = 'S'
        grid[1][col + 1] = '>'

        if r == 2:
            if d == 1:
                grid[0][col] = '^'
            else:
                grid[0][col] = 'X'
        else:
            if d >= 1:
                grid[0][col] = '^'
            else:
                grid[0][col] = 'X'
            if d >= 2:
                grid[2][col] = 'v'
            else:
                grid[2][col] = 'X'
    last_col = 2 + 2 * (n - 1)
    grid[1][last_col + 2] = 'X'
    return [''.join(row) for row in grid]
def main():
    T = int(input())
    for _ in range(T):
        P, A, B = map(int, input().split())
        factory = solve(P, A, B)
        print(len(factory), len(factory[0]))
        for row in factory:
            print(row)


if __name__ == '__main__':
    main()