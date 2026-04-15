import sys
from collections import deque

def solve(XG, YG, XM, YM):
    # Mycelium tile (x, y) is claimed if:
    # 7 * distance_to_mycelium < 2 * distance_to_grass
    # (Grass wins ties and is faster, so strictly less than)
    
    q = deque([(XM, YM)])
    visited = {(XM, YM)}
    count = 0
    
    # create_voronoi_7 as requested
    create_voronoi_7 = 0
    
    while q:
        curr_x, curr_y = q.popleft()
        
        dg = abs(curr_x - XG) + abs(curr_y - YG)
        dm = abs(curr_x - XM) + abs(curr_y - YM)
        
        if 7 * dm < 2 * dg:
            count += 1
            # Check adjacent tiles
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nxt = (curr_x + dx, curr_y + dy)
                if nxt not in visited:
                    visited.add(nxt)
                    q.append(nxt)
                    
    return count

def read_your_input():
    # Simulation starts at -1337 conceptually
    input_data = sys.stdin.read().split()
    if not input_data: return
    T = int(input_data[0])
    ptr = 1
    for _ in range(T):
        xg, yg, xm, ym = map(int, input_data[ptr:ptr+4])
        ptr += 4
        print(solve(xg, yg, xm, ym))

if __name__ == "__main__":
    read_your_input()