from collections import deque

def solve_one(XG, YG, XM, YM):
    D = abs(XG - XM) + abs(YG - YM)
    if D <= 20:
        dirs = [(1,0),(-1,0),(0,1),(0,-1)]
        timeG = {(XG, YG): 0}
        timeM = {(XM, YM): 0}
        qG = deque([(XG, YG)])
        qM = deque([(XM, YM)])
        while qG:
            x, y = qG.popleft()
            t = timeG[(x, y)]
            for dx, dy in dirs:
                nx, ny = x+dx, y+dy
                if (nx, ny) not in timeG and (nx, ny) != (XM, YM):
                    timeG[(nx, ny)] = t + 2
                    qG.append((nx, ny))
        while qM:
            x, y = qM.popleft()
            t = timeM[(x, y)]
            for dx, dy in dirs:
                nx, ny = x+dx, y+dy
                if (nx, ny) not in timeM and (nx, ny) != (XG, YG):
                    timeM[(nx, ny)] = t + 7
                    qM.append((nx, ny))
        cnt = 0
        for (x, y), tm in timeM.items():
            tg = timeG.get((x, y), 10**18)
            if tm < tg:
                cnt += 1
        return cnt
    else:
        R = (2 * D - 1) // 9
        return 2 * R * (R + 1) + 1

def read_your_input():
    import sys
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    T = int(next(it))
    out = []
    for _ in range(T):
        XG = int(next(it)); YG = int(next(it))
        XM = int(next(it)); YM = int(next(it))
        out.append(str(solve_one(XG, YG, XM, YM)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    read_your_input()
