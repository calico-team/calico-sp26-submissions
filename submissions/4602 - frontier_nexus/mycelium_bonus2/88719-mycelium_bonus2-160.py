import sys
import heapq

def solve():
    # Read all tokens from standard input
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    idx = 1
    
    out = []
    for _ in range(T):
        xG = int(input_data[idx])
        yG = int(input_data[idx+1])
        xM = int(input_data[idx+2])
        yM = int(input_data[idx+3])
        idx += 4
        
        # Translate so Mycelium is at (0,0)
        start_x = xG - xM
        start_y = yG - yM
        D = abs(start_x) + abs(start_y)
        
        # The absolute maximum radius Mycelium can spread before Grass 
        # completely surrounds it is bounded by 5*R <= 2*D.
        # We add +5 to give Grass plenty of room to pathfind around the edges.
        R = (2 * D) // 5 + 5
        
        pq = []
        grass_time = {}
        
        # If Grass starts inside our calculated interaction box, start from Grass
        if abs(start_x) <= R and abs(start_y) <= R:
            heapq.heappush(pq, (0, start_x, start_y))
            grass_time[(start_x, start_y)] = 0
        else:
            # Seed the perimeter of the interaction box with Grass's pure Manhattan arrival times
            for i in range(-R, R + 1):
                for j in [-R, R]:
                    t = 2 * (abs(i - start_x) + abs(j - start_y))
                    heapq.heappush(pq, (t, i, j))
                    grass_time[(i, j)] = t
            for j in range(-R + 1, R):
                for i in [-R, R]:
                    t = 2 * (abs(i - start_x) + abs(j - start_y))
                    heapq.heappush(pq, (t, i, j))
                    grass_time[(i, j)] = t
                    
        # Dijkstra pathfinding inward
        while pq:
            t, x, y = heapq.heappop(pq)
            
            # Skip if we've already found a faster path
            if t > grass_time.get((x, y), float('inf')):
                continue
                
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nx, ny = x + dx, y + dy
                
                # Keep search strictly within the interaction bounding box
                if -R <= nx <= R and -R <= ny <= R:
                    dist_M = abs(nx) + abs(ny)
                    t_next = t + 2
                    
                    # Tie-breaker rule: If Mycelium beats Grass to this tile, Grass acts as if it's a wall.
                    if 7 * dist_M <= t_next - 1:
                        pass 
                    else:
                        if t_next < grass_time.get((nx, ny), float('inf')):
                            grass_time[(nx, ny)] = t_next
                            heapq.heappush(pq, (t_next, nx, ny))
                            
        # Count all tiles where Mycelium outpaces Grass
        myc_count = 0
        for i in range(-R, R + 1):
            for j in range(-R, R + 1):
                dist_M = abs(i) + abs(j)
                
                # We only need to check tiles physically reachable by Mycelium
                if dist_M > R:
                    continue
                    
                t_M = 7 * dist_M
                t_G = grass_time.get((i, j), -1)
                
                if t_G == -1:
                    # Grass never reached it, Mycelium gets it
                    myc_count += 1
                else:
                    if t_M <= t_G - 1:
                        myc_count += 1
                        
        out.append(str(myc_count))
        
    print('\n'.join(out))

if __name__ == '__main__':
    solve()