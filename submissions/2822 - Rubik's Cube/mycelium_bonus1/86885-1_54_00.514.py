import collections
import sys

def grow(gx, gy, mx, my):
    bg = [collections.deque() for i in range(8)]
    bm = [collections.deque() for i in range(8)]
    best = {}
    bg[0].append((gx, gy))
    bm[0].append((mx, my))
    best[(gx, gy)] = -0.1 
    best[(mx, my)] = 0
    grid = set()
    mc = 0
    mq = 1
    tick = -1337
    
    while mq > 0:
        idx = tick % 8
        while bg[idx]:
            x, y = bg[idx].popleft()
            if (x, y) in grid:
                continue
            grid.add((x, y))
            nt = tick + 2
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = x + dx, y + dy
                if (nx, ny) not in grid:
                    if nt - 0.1 < best.get((nx, ny), float('inf')):
                        best[(nx, ny)] = nt - 0.1
                        bg[nt % 8].append((nx, ny))
        while bm[idx]:
            x, y = bm[idx].popleft()
            mq -= 1
            if (x, y) in grid:
                continue
            grid.add((x, y))
            mc += 1
            nt = tick + 7
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = x + dx, y + dy
                if (nx, ny) not in grid:
                    if nt < best.get((nx, ny), float('inf')):
                        best[(nx, ny)] = nt
                        bm[nt % 8].append((nx, ny))
                        mq += 1
        tick += 1
    print(mc)

data = sys.stdin.read().split()
lines = int(data[0])
idx = 1
for i in range(lines):
    if idx + 3 >= len(data):
        break
    gx = int(data[idx])
    gy = int(data[idx+1])
    mx = int(data[idx+2])
    my = int(data[idx+3])
    idx += 4
    grow(gx, gy, mx, my)