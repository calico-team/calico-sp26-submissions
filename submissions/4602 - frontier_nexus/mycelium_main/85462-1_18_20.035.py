import collections

def solve():
    import sys
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    idx = 1
    
    for _ in range(T):
        xg = int(input_data[idx])
        yg = int(input_data[idx+1])
        xm = int(input_data[idx+2])
        ym = int(input_data[idx+3])
        idx += 4
        
        # BFS to count reachable mycelium tiles
        visited = set([(xm, ym)])
        queue = collections.deque([(xm, ym)])
        count = 0
        
        while queue:
            cx, cy = queue.popleft()
            count += 1
            
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = cx + dx, cy + dy
                
                if (nx, ny) not in visited:
                    dist_g = abs(nx - xg) + abs(ny - yg)
                    dist_m = abs(nx - xm) + abs(ny - ym)
                    
                    # Mycelium must arrive at a tick strictly less than Grass
                    # Grass reaches at tick 2 * dist_g
                    # Mycelium reaches at tick 7 * dist_m
                    if 7 * dist_m < 2 * dist_g:
                        visited.add((nx, ny))
                        queue.append((nx, ny))
        print(count)

if __name__ == "__main__":
    solve()