import sys
import heapq

def solve() -> None:
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    t = int(next(it))
    out = []

    for _ in range(t):
        xg = int(next(it)); yg = int(next(it))
        xm = int(next(it)); ym = int(next(it))

        dist = abs(xg - xm) + abs(yg - ym)

        if dist % 2 == 0:
            grass_reach = dist // 2
            mycelium_reach = dist // 2
            total = 1 + mycelium_reach * (mycelium_reach + 1) * 2
        else:
            grass_reach = dist // 2
            mycelium_reach = dist // 2 + 1
            total = 1 + mycelium_reach * (mycelium_reach + 1) * 2

        out.append(str(total))

    sys.stdout.write("\n".join(out))

def read_your_input():
    solve()

if __name__ == "__main__":
    solve()
