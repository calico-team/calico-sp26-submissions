def solve_one(XG, YG, XM, YM):
    from collections import deque
    MAX_T = 2000
    grass = {}
    q = deque()
    q.append((XG, YG, 0))
    grass[(XG, YG)] = 0
    while q:
        x, y, t = q.popleft()
        if t + 2 > MAX_T:
            continue
        for nx, ny in ((x+1,y),(x-1,y),(x,y+1),(x,y-1)):
            if (nx, ny) not in grass:
                grass[(nx, ny)] = t + 2
                q.append((nx, ny, t + 2))
    mycelium = {}
    q = deque()
    q.append((XM, YM, 0))
    mycelium[(XM, YM)] = 0
    while q:
        x, y, t = q.popleft()
        if t + 7 > MAX_T:
            continue
        for nx, ny in ((x+1,y),(x-1,y),(x,y+1),(x,y-1)):
            nt = t + 7
            if (nx, ny) in mycelium:
                continue
            gtime = grass.get((nx, ny), 10**9)
            if nt < gtime:
                mycelium[(nx, ny)] = nt
                q.append((nx, ny, nt))
    return len(mycelium)

def read_your_input():
    import sys
    data = sys.stdin.read().strip().split()
    if not data:
        return
    t = int(data[0])
    idx = 1
    out = []
    for _ in range(t):
        XG = int(data[idx]); YG = int(data[idx+1])
        XM = int(data[idx+2]); YM = int(data[idx+3])
        idx += 4
        out.append(str(solve_one(XG, YG, XM, YM)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    read_your_input()
