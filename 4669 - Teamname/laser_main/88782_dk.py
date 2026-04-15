# ﷽
import sys
input = sys.stdin.readline

def solve():
    k, n, m, p, q = map(int, input().split())

    s = {}

    x, y = map(int, input().split())
    s[(x, y)] = -1

    for i in range(1, k):
        x1, y1 = map(int, input().split())
        s[(x1, y1)] = i

    while True:
        x = (p + x) % n
        y = (q + y) % m

        if (x, y) in s:
            temp = s[(x, y)]
            if temp == -1:
                print(0)
            else:
                print(temp)
            return

t = int(input())
for _ in range(t):
    solve()