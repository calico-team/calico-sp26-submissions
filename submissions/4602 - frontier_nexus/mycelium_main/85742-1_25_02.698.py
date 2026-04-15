from collections import deque

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    T = int(data[0])
    idx = 1
    
    results = []
    for _ in range(T):
        XG, YG, XM, YM = map(int, data[idx:idx+4])
        idx += 4
        
        # BFS expansion times
        grass_time = {}
        mycelium_time = {}
        
        # Grass spreads every 2 ticks
        qg = deque()
        qg.append((XG, YG, 0))
        grass_time[(XG, YG)] = 0
        
        # Mycelium spreads every 7 ticks
        qm = deque()
        qm.append((XM, YM, 0))
        mycelium_time[(XM, YM)] = 0
        
        directions = [(1,0),(-1,0),(0,1),(0,-1)]
        
        # Expand grass
        while qg:
            x, y, t = qg.popleft()
            nt = t + 2
            for dx, dy in directions:
                nx, ny = x+dx, y+dy
                if (nx, ny) not in grass_time:
                    grass_time[(nx, ny)] = nt
                    qg.append((nx, ny, nt))
        
        # Expand mycelium
        while qm:
            x, y, t = qm.popleft()
            nt = t + 7
            for dx, dy in directions:
                nx, ny = x+dx, y+dy
                if (nx, ny) not in mycelium_time:
                    mycelium_time[(nx, ny)] = nt
                    qm.append((nx, ny, nt))
        
        # Count valid mycelium tiles
        count = 0
        for pos, mt in mycelium_time.items():
            gt = grass_time.get(pos, float('inf'))
            # Mycelium claims if it arrives strictly before grass
            # OR if both arrive same tick, grass wins
            if mt < gt:
                count += 1
        
        results.append(count)
    
    print("\n".join(map(str, results)))


if __name__ == "__main__":
    solve()
