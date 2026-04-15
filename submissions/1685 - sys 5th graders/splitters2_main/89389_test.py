input_cases = int(input())

for i in range(input_cases):
    input_data = input().strip().split()
    P = int(input_data[0]); A = int(input_data[1]); B = int(input_data[2])

    D = (2 ** A) * (3 ** B) + 20
    OFFSET = D + 50
    current_positions = [OFFSET]

    h = 2 * (A + B) + 5
    w = 2 * OFFSET + 10

    grid = [['.' for _ in range(w)] for _ in range(h)]
    grid[0][OFFSET] = 'v'

    row = 1

    for path in range(B):
        next_pos = []
        for col in current_positions:
            grid[row-1][col] = 'v'
            grid[row][col]   = 'S'
            grid[row][col-1] = '<'
            grid[row][col+1] = '>'
            grid[row][col-2] = 'v'
            grid[row][col+2] = 'v'
            grid[row+1][col] = 'v'
            next_pos.extend([col-2, col, col+2])
        current_positions = next_pos
        row += 2

    for path in range(A):
        next_pos = []
        for col in current_positions:
            grid[row-1][col] = 'v'
            grid[row][col]   = 'S'
            grid[row][col-1] = '<'
            grid[row][col+1] = '>'
            grid[row][col-2] = 'v'
            grid[row][col+2] = 'v'
            next_pos.extend([col-2, col+2])
        current_positions = next_pos
        row += 2

    for idx, col in enumerate(current_positions):
        grid[row-1][col] = 'v' if idx < P else 'X'

    print(h, w)
    for row_data in grid:
        print(''.join(row_data))