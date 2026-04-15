import heapq

def grow():
    line = list(map(int, input().split()))
    gx = line[0]
    gy = line[1]
    mx = line[2]
    my = line[3]
    pq = []
    heapq.heappush(pq, (1337, 'G', gx, gy))
    heapq.heappush(pq, (1337, 'M', mx, my))
    grid = set()
    mc = 0
    mq = 1
    
    while pq and mq > 0:
        t, org, x, y = heapq.heappop(pq)
        if org == 'M':
            mq -= 1
        if (x, y) in grid:
            continue
        grid.add((x, y))
        if org == 'M':
            mc += 1
            next_t = t + 7
        else:
            next_t = t + 2
        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            nx, ny = x + dx, y + dy
            if (nx, ny) not in grid:
                heapq.heappush(pq, (next_t, org, nx, ny))
                if org == 'M':
                    mq += 1
    print(mc)

lines = int(input())
for i in range(lines):
    grow()
