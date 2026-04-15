t = int(input())

for _ in range(t):
    n = int(input())
    s1_lines = []
    s2_lines = []
    for _ in range(n):
        s1_lines.append(input())
    for _ in range(n):
        s2_lines.append(input())

    s1c = [0] * n
    s2c = [0] * n

    for x in range(len(s1_lines)):
        for y in range(len(s1_lines)):
            if s1_lines[x][y] == "#":
                s1c[x] += 1
            if s2_lines[x][y] == "#":
                s2c[x] += 1

    maxvol = 0
    minvol = 0
    
    for r in range(len(s1_lines)):
        maxvol += s1c[r] * s2c[r]
        minvol += max(s1c[r], s2c[r])
    print(f"{maxvol} {minvol}")
    