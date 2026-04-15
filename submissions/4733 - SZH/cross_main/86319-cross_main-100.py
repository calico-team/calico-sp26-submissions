from collections import deque

N = int(input())

for i in range(N):
    x, y = map(int, input().split())

    base = deque([0, 1, 2, 3, 4])
    for a in range(x):
        for b in range(y):
            print(base[b], end="")
        print(" ")
        base.rotate(2)