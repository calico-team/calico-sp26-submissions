import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    P, A, B = map(int, input().split())
    n = 1
    m = 5
    grid = []
    row = ['>'] * (m-1) + ['>']
    grid.append("".join(row))
    print(n, m)
    for r in grid:
        print(r)
def read_your_input():
    pass