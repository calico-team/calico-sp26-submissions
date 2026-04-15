import sys
input = sys.stdin.readline

for i in range(int(input())):
    k, n, m, p, q = map(int, input().split())
    s = dict()
    sx = -1; sy = -1
    for i in range(k):
        x, y = map(int, input().split())
        if sx == -1:
            sx = x; sy = y
        s[(x, y)] = i
    x = sx; y = sy
    for i in range(1 << 30):
        x = (x + q) % n; y = (y + p) % m
        if (x, y) in s:
            print(s[(x, y)])
            break
