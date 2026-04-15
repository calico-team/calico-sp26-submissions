tests = int(input())
for s in range(tests):
    p, a, b = map(int, input().split())
    if a == 0 and b == 0:
        print("1 1\n^")
        continue
    total = pow(2, a) * pow(3, b)
    need = p
    steps = []
    while need > 0 and a > 0:
        half = total // 2
        take = need // half
        steps.append((2, take))
        need %= half
        total = half
        a -= 1
    while need > 0 and b > 0:
        half = total // 3
        take = need // half
        steps.append((3, take))
        need %= half
        total = half
        b -= 1
    rows = 5
    columns = 2 * len(steps) + 2
    grid = []
    for row in range(rows):
        line = []
        for column in range(columns):
            line.append(".")
        grid.append(line)
    grid[0][0] = "v"
    grid[1][0] = "v"
    grid[2][0] = ">"
    grid[2][1] = ">"
    for j in range(len(steps)):
        size, take = steps[j]
        column = 2 + 2 * j
        grid[2][column] = "s"
        if size == 2:
            if take == 1:
                grid[1][column] = "^"
                grid[0][column] = "^"
            else:
                grid[1][column] = "x"
        else:
            if take >= 1:
                grid[1][column] = "^"
                grid[0][column] = "^"
            else:
                grid[1][column] = "x"

            if take >= 2:
                grid[3][column] = "v"
                grid[4][column] = "v"
            else:
                grid[3][column] = "x"
        if j + 1 < len(steps):
            grid[2][column + 1] = ">"
        else:
            grid[2][column + 1] = "x"
    build = [str(rows) + " " + str(column)]
    for row in range(rows):
        build.append("".join(grid[row]))
    print("\n".join(build))