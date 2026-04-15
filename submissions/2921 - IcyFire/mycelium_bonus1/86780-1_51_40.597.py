import heapq

t = int(input())

for _ in range(t):
    gx, gy, mx, my = map(int, input().split())

    start_dist = abs(gx - mx) + abs(gy - my)
    dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    lim = 200 + start_dist
    own = {}
    own[(gx, gy)] = 'G'
    own[(mx, my)] = 'M'
    pq = []
    heapq.heappush(pq, (2, 'G', gx, gy))
    heapq.heappush(pq, (7, 'M', mx, my))
    # print(own)

    while pq:
        tme, o, x, y = heapq.heappop(pq)
        step = 2 if o == 'G' else 7

        for dx, dy in dirs:
            nx = x + dx
            ny = y + dy
            if abs(nx) > lim or abs(ny) > lim:
                continue
            if (nx, ny) not in own:
                own[(nx, ny)] = o
                heapq.heappush(pq, (tme + step, o, nx, ny))
                # print("!")
    res = 0
    for v in own.values():
        if v == 'M':
            res += 1

    print(res)