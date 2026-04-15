#jai srirama hope i get this right
from math import lcm
t = int(input())
for i in range(t):
    k, n, m, p, q = map(int, input().split())
    a = []
    for j in range(k):
        x, y = map(int, input().split())
        a.append((x, y))
    s = {(x, y): i for i, (x, y) in enumerate(a)}
    x, y = a[0]
    for c in range(lcm(n, m)):
        x = (x + q) % n
        y = (y + p) % m
        if (x, y) in s:
            print(s[(x, y)])
            break
    else:
        print(-1)