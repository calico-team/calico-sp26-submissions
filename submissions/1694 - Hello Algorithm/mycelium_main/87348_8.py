import sys
import heapq

input = sys.stdin.readline

t_num = int(input())

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

res = []

for _ in range(t_num):
    xg, yg, xm, ym = map(int, input().split())

    xg -= xm
    yg -= ym

    D = abs(xg) + abs(yg)

    R = (2 * D) // 5 + 10
    size = 2 * R + 1
    offset = R

    INF = 10**18

    dist = [[INF] * size for _ in range(size)]
    owner = [[0] * size for _ in range(size)]

    pq = []

    if abs(xg) <= R and abs(yg) <= R:
        dist[xg + offset][yg + offset] = 0
        owner[xg + offset][yg + offset] = 1
        heapq.heappush(pq, (0, 1, xg, yg))

    dist[offset][offset] = 0
    owner[offset][offset] = 2
    heapq.heappush(pq, (0, 2, 0, 0))

    while pq:
        t, typ, x, y = heapq.heappop(pq)

        if abs(x) > R or abs(y) > R:
            continue

        if dist[x + offset][y + offset] != t:
            continue

        if owner[x + offset][y + offset] != typ:
            continue

        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]

            if abs(nx) > R or abs(ny) > R:
                continue

            nt = t + (2 if typ == 1 else 7)

            cx = nx + offset
            cy = ny + offset

            if dist[cx][cy] > nt:
                dist[cx][cy] = nt
                owner[cx][cy] = typ
                heapq.heappush(pq, (nt, typ, nx, ny))

            elif dist[cx][cy] == nt:
                if owner[cx][cy] == 2 and typ == 1:
                    owner[cx][cy] = 1
                    heapq.heappush(pq, (nt, typ, nx, ny))

    ans = 0

    for x in range(-R, R + 1):
        for y in range(-R, R + 1):
            if owner[x + offset][y + offset] == 2:
                ans += 1

    res.append(str(ans))

sys.stdout.write('\n'.join(res) + '\n')