import collections

def solve():
    try:
        line = input().split()
        if not line: return
        T = int(line[0])
    except EOFError:
        return

    for _ in range(T):
        coords = list(map(int, input().split()))
        xg, yg, xm, ym = coords
        
        # BFS to find all tiles where Mycelium arrives strictly before Grass
        # Start at the initial Mycelium tile
        visited = set([(xm, ym)])
        queue = collections.deque([(xm, ym)])
        count = 0
        
        while queue:
            curr_x, curr_y = queue.popleft()
            count += 1
            
            # Check 4 neighbors
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = curr_x + dx, curr_y + dy
                
                if (nx, ny) not in visited:
                    # Manhattan distances
                    dist_g = abs(nx - xg) + abs(ny - yg)
                    dist_m = abs(nx - xm) + abs(ny - ym)
                    
                    # Time calculation based on problem rules
                    time_g = 2 * dist_g
                    time_m = 7 * dist_m
                    
                    # Mycelium only takes the tile if it arrives strictly first
                    if time_m < time_g:
                        visited.add((nx, ny))
                        queue.append((nx, ny))
        
        print(count)

if __name__ == "__main__":
    solve()