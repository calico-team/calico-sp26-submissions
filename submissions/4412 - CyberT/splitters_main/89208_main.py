import sys
from matplotlib.pyplot import grid
from matplotlib.pyplot import grid
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    P, A, B = map(int, input().split())
    g = []
    width = 20
    height = 1 + A + B
    row = list("." * width)
    row[0] = '>'
    for i in range(1, width-1):
        row[i] = '>'
    row[-1] = 'v'
    g.append("".join(row))
    cur_col = width - 1
    for i in range(A):
        row = list("." * width)
        row[cur_col] = 'S'
        row[cur_col-1] = 'X'
        row[cur_col+1-1] = 'v' 
        g.append("".join(row))
    for i in range(B):
        row = list("." * width)
        row[cur_col] = 'S'
        row[cur_col-1] = 'X'
        if cur_col+1 < width:
            row[cur_col+1] = '>'
        g.append("".join(row))
    row = list("." * width)
    row[cur_col] = 'v'
    g.append("".join(row))
    print(len(grid), width)
    for r in grid:
        print(r)
def read_your_input():
    pass