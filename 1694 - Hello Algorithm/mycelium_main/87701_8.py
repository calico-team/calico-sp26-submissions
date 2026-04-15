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

    R = 3 * D + 10
    size = 2 * R + 1
    offset = R

    INF = 10**18

    time_arr = [[INF] * size for _ in range(size)]
    owner = [[0] * size for _ in range(size)]

    pq = []

    if abs(xg) <= R and abs(yg) <= R:
        gx, gy = xg + offset, yg + offset
        time_arr[gx][gy] = 0
        owner[gx][gy] = 1
        heapq.heappush(pq, (0, 1, xg, yg))

    mx, my = offset, offset
    time_arr[mx][my] = 0
    owner[mx][my] = 2
    heapq.heappush(pq, (0, 2, 0, 0))

    while pq:
        t, typ, x, y = heapq.heappop(pq)

        cx = x + offset
        cy = y + offset

        if abs(x) > R or abs(y) > R:
            continue

        if time_arr[cx][cy] != t or owner[cx][cy] != typ:
            continue

        nt = t + (2 if typ == 1 else 7)

        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]

            if abs(nx) > R or abs(ny) > R:
                continue

            nx_i = nx + offset
            ny_i = ny + offset

            if time_arr[nx_i][ny_i] > nt:
                time_arr[nx_i][ny_i] = nt
                owner[nx_i][ny_i] = typ
                heapq.heappush(pq, (nt, typ, nx, ny))

            elif time_arr[nx_i][ny_i] == nt:
                if owner[nx_i][ny_i] == 2 and typ == 1:
                    owner[nx_i][ny_i] = 1
                    heapq.heappush(pq, (nt, typ, nx, ny))

    ans = 0
    for i in range(size):
        for j in range(size):
            if owner[i][j] == 2:
                ans += 1

    res.append(str(ans))

sys.stdout.write('\n'.join(res) + '\n')