import sys

input = sys.stdin.read
data = input().splitlines()

idx = 0
T = int(data[idx])
idx += 1

for _ in range(T):
    N = int(data[idx])
    idx += 1

    S1 = []
    for i in range(N):
        S1.append(data[idx])
        idx += 1

    S2 = []
    for i in range(N):
        S2.append(data[idx])
        idx += 1

    max_vol = 0
    min_vol = 0
    for r in range(N):
        a = S1[r].count('#')
        b = S2[r].count('#')
        max_vol += a * b
        min_vol += max(a, b)

    print(max_vol, min_vol)