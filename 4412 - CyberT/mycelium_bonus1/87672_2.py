def solve():
    import sys
    data = sys.stdin.read().strip().split()
    if not data:
        return
    t = int(data[0])
    out = []
    idx = 1
    for _ in range(t):
        XG = int(data[idx]); YG = int(data[idx+1]); XM = int(data[idx+2]); YM = int(data[idx+3])
        idx += 4
        
        if max(abs(XG), abs(YG), abs(XM), abs(YM)) > 200:
            dx = abs(XG - XM)
            dy = abs(YG - YM)
            dist = dx + dy
            if dist == 0:
                out.append("1")
            else:
                if 7 * 1 < 2 * dist:
                    out.append("1")
                else:
                    out.append("0")
            continue
        
        from collections import deque
        visited = set()
        q = deque()
        q.append((XM, YM))
        visited.add((XM, YM))
        mycelium_tiles = set()
        mycelium_tiles.add((XM, YM))
        
        steps = 0
        max_steps = 1000
        while q and steps < max_steps:
            next_q = set()
            for _ in range(len(q)):
                x, y = q.popleft()
                for nx, ny in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
                    if (nx, ny) in visited:
                        continue
                    dg = abs(nx - XG) + abs(ny - YG)
                    dm = abs(nx - XM) + abs(ny - YM)
                    time_grass = 2 * dg
                    time_mycelium = 7 * dm
                    if time_mycelium < time_grass:
                        mycelium_tiles.add((nx, ny))
                        visited.add((nx, ny))
                        next_q.add((nx, ny))
                    elif time_mycelium == time_grass:
                        visited.add((nx, ny))
            q = deque(next_q)
            steps += 1
        out.append(str(len(mycelium_tiles)))
    sys.stdout.write("\n".join(out))

def read_your_input():
    return sys.stdin.read()

if __name__ == "__main__":
    solve()