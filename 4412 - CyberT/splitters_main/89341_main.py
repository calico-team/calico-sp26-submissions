import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    P, A, B = map(int, input().split())
    g = []
    w = 20
    row = list("." * w)
    for i in range(w-1):
        row[i] = '>'
    row[w-1] = 'v'
    g.append("".join(row))
    col = w - 1
    for _ in range(A):
        row = list("." * w)
        row[col] = 'S'
        if col-1 >= 0:
            row[col-1] = 'X'
        row[col] = 'S'
        g.append("".join(row))
    for _ in range(B):
        row = list("." * w)
        row[col] = 'S'
        if col-1 >= 0:
            row[col-1] = 'X'
        if col+1 < w:
            row[col+1] = '>'
        g.append("".join(row))
    row = list("." * w)
    row[col] = 'v'
    g.append("".join(row))
    print(len(g), w)
    for r in g:
        print(r)
def read_your_input():
    pass