import sys
import heapq #polease :pray:

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
        events = [(2, 0, xg, yg), (7, 1, xm, ym)]
        heapq.heapify(events)

        count = 1
        limit = 500 # less is fine
        while events:
            tick, invinciblewobblyedit, x, y = heapq.heappop(events)
            if tick > limit:
                break
            neighbors = [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]
            for nx, ny in neighbors:
                if (nx, ny) in owner:
                    continue
                owner[(nx, ny)] = invinciblewobblyedit
                if invinciblewobblyedit == 0:
                    heapq.heappush(events, (tick + 2, 0, nx, ny))
                else:
                    count += 1
                    heapq.heappush(events, (tick + 7, 1, nx, ny))

        print(count)

main()