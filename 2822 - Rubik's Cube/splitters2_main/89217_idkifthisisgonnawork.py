def tang():
    params = list(map(int, input().split()))
    target = (2 ** params[1]) * (3 ** params[2])
    if params[0] == target:
        print('1 1')
        print('>')
        return
    bases = [2] * params[1] + [3] * params[2]
    cl = []
    current = params[0]
    
    for b in reversed(bases):
        cl.append(current % b)
        current = current // b
    cl.reverse()
    grid = [['.' for j in range(3 * len(bases) + 2)] for i in range(5)]
    grid[0][0] = 'v'
    grid[1][0] = 'v'
    grid[2][0] = '>'
    grid[2][1] = '>'
    
    for i in range(len(bases)):
        b = bases[i]
        c = cl[i]
        col = 2 + 3 * i
        grid[2][col] = 'S'
        if i > 0:
            grid[2][col-2] = '>'
            grid[2][col-1] = '>'
            
        if b == 2:
            if c == 1:
                grid[1][col] = '^'
                grid[0][col] = '^'
            else:
                grid[1][col] = 'X'
        elif b == 3:
            if c == 2:
                grid[1][col] = '^'
                grid[0][col] = '^'
                grid[3][col] = 'v'
                grid[4][col] = 'v'
            elif c == 1:
                grid[1][col] = '^'
                grid[0][col] = '^'
                grid[3][col] = 'X'
            else:
                grid[1][col] = 'X'
                grid[3][col] = 'X'
                
    lc = 2 + 3 * (len(bases) - 1)
    grid[2][lc + 1] = 'X'
    print(f'{5} {3 * len(bases) + 2}')
    for r in range(5):
        print(''.join(grid[r]))

lines = int(input().strip())
for i in range(lines):
    tang()