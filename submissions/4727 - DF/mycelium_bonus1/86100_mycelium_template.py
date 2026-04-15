import heapq
import sys

DIRS = ((1, 0), (-1, 0), (0, 1), (0, -1))

def solve_one(xg: int, yg: int, xm: int, ym: int) -> int:
    dx = xg - xm
    dy = yg - ym
    s = abs(dx) + abs(dy)
    limit = s + 12
    grass_start = (dx, dy)
    pq = [(0, 0, grass_start[0], grass_start[1]), (0, 1, 0, 0)]
    occupied = {}
    mycelium_count = 0
    while pq:
        t, typ, x, y = heapq.heappop(pq)
        if (x, y) in occupied:
            continue
        if abs(x) > limit or abs(y) > limit:
            continue
        occupied[(x, y)] = typ
        if typ == 1:
            mycelium_count += 1
        step = 2 if typ == 0 else 7
        for ddx, ddy in DIRS:
            nx, ny = x + ddx, y + ddy
            if (nx, ny) not in occupied:
                heapq.heappush(pq, (t + step, typ, nx, ny))
    return mycelium_count

def main() -> None:
    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    t = int(next(it))
    out = []
    for _ in range(t):
        xg = int(next(it))
        yg = int(next(it))
        xm = int(next(it))
        ym = int(next(it))
        out.append(str(solve_one(xg, yg, xm, ym)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()
