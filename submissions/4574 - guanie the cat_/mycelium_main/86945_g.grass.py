for T in range(int(input())):
    gx, gy, mx, my = [(int(i) + 20) for i in input().split()]
    grid = [[0 for i in range(40)] for j in range(40)]
    grid[gx][gy] = 1
    grid[mx][my] = 2
    stop = False
    turn = 1
    outergrass = set()
    outergrass.add((gx, gy))
    outermycelium = set()
    outermycelium.add((mx, my))
    while stop == False:
        if turn % 2 == 0:
            temp = set()
            for i in outergrass:
                if grid[i[0] - 1][i[1]] == 0:
                    grid[i[0] - 1][i[1]] = 1
                    temp.add((i[0] - 1, i[1]))
                if grid[i[0] + 1][i[1]] == 0:
                    grid[i[0] + 1][i[1]] = 1
                    temp.add((i[0] + 1, i[1]))
                if grid[i[0]][i[1] - 1] == 0:
                    grid[i[0]][i[1] - 1] = 1
                    temp.add((i[0], i[1] - 1))
                if grid[i[0]][i[1] + 1] == 0:
                    grid[i[0]][i[1] + 1] = 1
                    temp.add((i[0], i[1] + 1))
            outergrass = temp
        if turn % 7 == 0:
            temp = set()
            for i in outermycelium:
                if grid[i[0] - 1][i[1]] == 0:
                    grid[i[0] - 1][i[1]] = 2
                    temp.add((i[0] - 1, i[1]))
                if grid[i[0] + 1][i[1]] == 0:
                    grid[i[0] + 1][i[1]] = 2
                    temp.add((i[0] + 1, i[1]))
                if grid[i[0]][i[1] - 1] == 0:
                    grid[i[0]][i[1] - 1] = 2
                    temp.add((i[0], i[1] - 1))
                if grid[i[0]][i[1] + 1] == 0:
                    grid[i[0]][i[1] + 1] = 2
                    temp.add((i[0], i[1] + 1))
            outermycelium = temp
        if outermycelium == set():
            stop = True
        turn += 1
    ans = 0
    for i in grid:
        for j in i:
            if j == 2:
                ans += 1
    print(ans)