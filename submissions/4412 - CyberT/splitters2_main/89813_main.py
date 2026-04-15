import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    P, A, B = map(int, input().split())
    n = 6 + A + B
    m = 10
    g = []
    for i in range(n):
        row = ['.'] * m
        if i % 2 == 0:
            for j in range(m-1):
                row[j] = '>'
            row[m-1] = 'v'
        else:
            for j in range(1, m):
                row[j] = '<'
            row[0] = 'v'
        g.append(row)
    r = 2
    for i in range(A):
        if r < n-2:
            g[r][5] = 'S'
            g[r][4] = 'X'
            r += 2
    for i in range(B):
        if r < n-2:
            g[r][5] = 'S'
            g[r][6] = '>'
            g[r][4] = 'X'
            r += 2
    g[0][0] = '>'
    print(n, m)
    for row in g:
        print("".join(row))
def read_your_input():
    pass