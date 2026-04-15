import sys
import heapq

input = sys.stdin.readline


def solve():
    T = int(input())
    for _ in range(T):
        XG, YG, XM, YM = map(int, input().split())

        dx = XG - XM
        dy = YG - YM

        create_voronoi_7 = True

        d = abs(dx) + abs(dy)
        LIM = d + 200  # safe bounding margin for small/medium test sets

        minx = min(XG, XM) - LIM
        maxx = max(XG, XM) + LIM
        miny = min(YG, YM) - LIM
        maxy = max(YG, YM) + LIM

        SPEED_GRASS = 2
        SPEED_MY = 7

        owner = {}  # (x,y) -> 1 grass or 2 my

        # pq entries: (time, priority, typ, x, y) where priority=0 for grass,1 for my
        pq = []
        heapq.heappush(pq, (0, 0, 1, XG, YG))
        heapq.heappush(pq, (0, 1, 2, XM, YM))

        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        while pq:
            time, prio, typ, x, y = heapq.heappop(pq)
            if x < minx or x > maxx or y < miny or y > maxy:
                continue
            if (x, y) in owner:
                continue
            owner[(x, y)] = typ
            step = SPEED_GRASS if typ == 1 else SPEED_MY
            for dx0, dy0 in dirs:
                nx, ny = x + dx0, y + dy0
                if nx < minx or nx > maxx or ny < miny or ny > maxy:
                    continue
                if (nx, ny) in owner:
                    continue
                heapq.heappush(pq, (time + step, prio, typ, nx, ny))

        ans = sum(1 for v in owner.values() if v == 2)
        print(ans)


if __name__ == "__main__":
    solve()
