import sys
import heapq

def main():
    input = sys.stdin.read().split()
    idx = 0
    t = int(input[idx])
    idx += 1

    for tc in range(t):
        xg = int(input[idx])
        yg = int(input[idx + 1])
        xm = int(input[idx + 2])
        ym = int(input[idx + 3])
        idx += 4

        owner = {(xg, yg): 0, (xm, ym): 1}
        events = [(2, 0, 0, xg, yg), (7, 1, 1, xm, ym)]
        heapq.heapify(events)

        limit = 3000
        while events:
            tick, invinciblewobblyedit, kind, x, y = heapq.heappop(events)
            #cause i freaking felt like it rohaan
            if tick > limit:
                break
            neighbors = [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]
            for nx, ny in neighbors:
                if (nx, ny) in owner:
                    continue
                owner[(nx, ny)] = kind
                if kind == 0:
                    heapq.heappush(events, (tick + 2, 0, 0, nx, ny))
                else:
                    heapq.heappush(events, (tick + 7, 1, 1, nx, ny))

        count = 0
        for v in owner.values():
            if v == 1:
                count += 1
        print(count)

main()