import sys

data = sys.stdin.read().split()
t = int(data[0])
idx = 1
out_lines = []

for _ in range(t):
    n = int(data[idx]); idx += 1
    
    S1 = []
    for __ in range(n):
        S1.append(data[idx]); idx += 1
    
    S2 = []
    for __ in range(n):
        S2.append(data[idx]); idx += 1
    
    a = [0] * n
    for y in range(n):
        cnt = 0
        for x in range(n):
            if S1[x][y] == '#':
                cnt += 1
        a[y] = cnt
    
    b = [0] * n
    for y in range(n):
        cnt = 0
        for z in range(n):
            if S2[y][z] == '#':
                cnt += 1
        b[y] = cnt
    
    Vmax = 0
    Vmin = 0
    for y in range(n):
        Vmax += a[y] * b[y]
        Vmin += max(a[y], b[y])
    
    out_lines.append(f"{Vmax} {Vmin}")

sys.stdout.write("\n".join(out_lines))









