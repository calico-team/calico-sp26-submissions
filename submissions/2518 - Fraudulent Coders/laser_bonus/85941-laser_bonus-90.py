import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    k, n, m, p, q = map(int, input().split())
    x, y = 0, 0
    vis = set([])
    ast = {}
    for j in range(k):
        a, b = map(int, input().split())
        if j == 0:
            x, y = a, b
        ast[(a, b)] = j
    vis.add((x, y))
    while True:
        x += q
        y += p
        if x >= n:
            x -= n
        if y >= m:
            y -= m
        if (x, y) in ast:
            print(ast[(x, y)])
            break
