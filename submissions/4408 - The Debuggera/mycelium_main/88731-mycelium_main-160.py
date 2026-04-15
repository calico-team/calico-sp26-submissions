import heapq
import sys


def solve_one(Xg, Yg, Xm, Ym):
    D = abs(Xg - Xm) + abs(Yg - Ym)
    # Mycelium stays in an O(D) neighborhood of the two seeds; clip search to a box.
    R = max(60, 3 * D + 100)

    def in_box(x, y):
        return (
            abs(x - Xg) <= R
            and abs(y - Yg) <= R
            and abs(x - Xm) <= R
            and abs(y - Ym) <= R
        )

    owner = {}
    owner[(Xg, Yg)] = "G"
    owner[(Xm, Ym)] = "M"

    pq = []

    def push(t, typ, x, y):
        if not in_box(x, y):
            return
        tie = 0 if typ == "G" else 1
        heapq.heappush(pq, (t, tie, x, y, typ))

    for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
        nx, ny = Xg + dx, Yg + dy
        if (nx, ny) not in owner:
            push(2, "G", nx, ny)
    for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
        nx, ny = Xm + dx, Ym + dy
        if (nx, ny) not in owner:
            push(7, "M", nx, ny)

    myc = 1
    steps = 0
    max_steps = 8_000_000
    while pq and steps < max_steps:
        t, _tie, x, y, typ = heapq.heappop(pq)
        steps += 1
        if (x, y) in owner:
            continue
        if not in_box(x, y):
            continue
        owner[(x, y)] = typ
        if typ == "M":
            myc += 1
        dt = 2 if typ == "G" else 7
        for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nx, ny = x + dx, y + dy
            if (nx, ny) not in owner:
                push(t + dt, typ, nx, ny)

    return myc


def main():
    data = sys.stdin.read().split()
    it = iter(data)
    T = int(next(it))
    out = []
    for _ in range(T):
        Xg = int(next(it))
        Yg = int(next(it))
        Xm = int(next(it))
        Ym = int(next(it))
        out.append(str(solve_one(Xg, Yg, Xm, Ym)))
    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
