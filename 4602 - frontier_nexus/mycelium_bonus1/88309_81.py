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
        
        # Priority Queue stores: (arrival_time, type, x, y)
        pq = []
        heapq.heappush(pq, (0, 'G', xG, yG))
        heapq.heappush(pq, (0, 'M', xM, yM))
        
        visited = {}
        myc_count = 0
        
        # Track how many Mycelium expansions are still in the queue
        active_M = 1 
        
        # Terminate early the moment Mycelium is completely surrounded
        while active_M > 0 and pq:
            time, typ, x, y = heapq.heappop(pq)
            
            if typ == 'M':
                active_M -= 1
                
            # If the tile was already claimed (likely by Grass), skip
            if (x, y) in visited:
                continue
                
            # Claim the tile
            visited[(x, y)] = typ
            if typ == 'M':
                myc_count += 1
                
            # Expand to neighbors
            next_time = time + 2 if typ == 'G' else time + 7
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nx, ny = x + dx, y + dy
                if (nx, ny) not in visited:
                    heapq.heappush(pq, (next_time, typ, nx, ny))
                    if typ == 'M':
                        active_M += 1
                        
        out.append(str(myc_count))
        
    print('\n'.join(out))

if __name__ == '__main__':
    solve()