import sys


input_data = sys.stdin.read().split()
t = int(input_data[0])
idx = 1
out_lines = []
for _ in range(t):
    N = int(input_data[idx]); idx += 1
    S1 = []
    for __ in range(N):
        S1.append(input_data[idx]); idx += 1
    S2 = []
    for __ in range(N):
        S2.append(input_data[idx]); idx += 1
        
    a = [0] * N
    for y in range(N):
        cnt = 0
        for x in range(N):
            if S1[x][y] == '#':
                cnt += 1
        a[y] = cnt
        
    b = [0] * N
    for y in range(N):
        cnt = 0
        for z in range(N):
            if S2[y][z] == '#':
                cnt += 1
        b[y] = cnt
        
    Vmax = 0
    Vmin = 0
    for y in range(N):
        Vmax += a[y] * b[y]
        Vmin += max(a[y], b[y])
        
    out_lines.append(f"{Vmax} {Vmin}")
    
sys.stdout.write("\n".join(out_lines))














