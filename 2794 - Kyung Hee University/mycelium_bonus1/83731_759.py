import sys
input = sys.stdin.readline

yv = (-1, 0, 0, 1); xv = (0, -1, 1, 0)
for i in range(int(input())):
    xg, yg, xm, ym = map(int, input().split())
    vis = [[False] * 1000 for i in range(1000)]
    vis[xg][yg] = 1
    vis[xm][ym] = 2
    q1 = [(xg, yg)]
    q2 = [(xm, ym)]
    area = 1
    for t in range(1, 1400):
        if t % 2 == 0:
            qn = []
            for x, y in q1:
                for k in range(4):
                    if -499 <= x+xv[k] <= 499 and -499 <= y+yv[k] <= 499:
                        if not vis[x+xv[k]][y+yv[k]]:
                            vis[x+xv[k]][y+yv[k]] = 1
                            qn.append((x+xv[k], y+yv[k]))
            q1 = qn
        if t % 7 == 0:
            qn = []
            for x, y in q2:
                for k in range(4):
                    if -499 <= x+xv[k] <= 499 and -499 <= y+yv[k] <= 499:
                        if not vis[x+xv[k]][y+yv[k]]:
                            vis[x+xv[k]][y+yv[k]] = 2
                            area += 1
                            qn.append((x+xv[k], y+yv[k]))
            q2 = qn
    print(area)
