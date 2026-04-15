import sys
input = sys.stdin.readline
from fractions import Fraction as F
from graphlib import TopologicalSorter as TS

yv = (-1, 0, 0, 1); xv = (0, -1, 1, 0)
ev = ('^', '<', '>', 'v')
rev = ('v', '>', '<', '^')
for i in range(int(input())):
    flag = False
    n, m = map(int, input().split())
    grid = [input().strip() for i in range(n)]

    graph = dict()
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'S':
                s = set()
                for k in range(4):
                    if 0 <= i+yv[k] < n and 0 <= j+xv[k] < m:
                        if grid[i+yv[k]][j+xv[k]] == 'X' or (grid[i+yv[k]][j+xv[k]] in ev and grid[i+yv[k]][j+xv[k]] != rev[k]):
                            s.add((i+yv[k], j+xv[k]))
                graph[(i, j)] = s
            elif grid[i][j] in ev:
                s = set()
                k = ev.index(grid[i][j])
                if 0 <= i+yv[k] < n and 0 <= j+xv[k] < m:
                    s.add((i+yv[k], j+xv[k]))
                graph[(i, j)] = s
    ts = list(TS(graph).static_order())[::-1]

    chance = [[0] * m for i in range(n)]; chance[0][0] = F(1)
    for y, x in ts:
        if grid[y][x] == 'S':
            c = 0
            for k in range(4):
                if 0 <= y+yv[k] < n and 0 <= x+xv[k] < m:
                    if grid[y+yv[k]][x+xv[k]] == 'X' or (grid[y+yv[k]][x+xv[k]] in ev and grid[y+yv[k]][x+xv[k]] != rev[k]):
                        c += 1
            e = chance[y][x] / c
            for k in range(4):
                if 0 <= y+yv[k] < n and 0 <= x+xv[k] < m:
                    if grid[y+yv[k]][x+xv[k]] == 'X' or (grid[y+yv[k]][x+xv[k]] in ev and grid[y+yv[k]][x+xv[k]] != rev[k]):
                        chance[y+yv[k]][x+xv[k]] += e
        elif grid[y][x] in ev:
            k = ev.index(grid[y][x])
            if 0 <= y+yv[k] < n and 0 <= x+xv[k] < m:
                chance[y+yv[k]][x+xv[k]] += chance[y][x]
            else:
                print(chance[y][x].numerator, chance[y][x].denominator)
                flag = True
                break
    if not flag:
        print(0, 1)
