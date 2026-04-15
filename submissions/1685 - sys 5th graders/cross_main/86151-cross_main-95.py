import sys

input = sys.stdin.read
data = input().split()

T = int(data[0])
index = 1
for _ in range(T):
    N = int(data[index])
    M = int(data[index + 1])
    index += 2
    for i in range(N):
        row = [(i + 2 * j) % 5 for j in range(M)]
        print(' '.join(map(str, row)))