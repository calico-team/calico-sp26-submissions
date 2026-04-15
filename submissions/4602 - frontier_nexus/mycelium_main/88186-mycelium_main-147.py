import sys

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
        
        # Grid stores 'G' for Grass and 'M' for Mycelium
        grid = {}
        grid[(xG, yG)] = 'G'
        grid[(xM, yM)] = 'M'
        
        # Track the advancing perimeters
        grass_front = [(xG, yG)]
        myc_front = [(xM, yM)]
        
        myc_count = 1
        tick = 1
        
        # The loop naturally terminates when Mycelium is completely surrounded by Grass
        while myc_front:
            next_G_front = set()
            next_M_front = set()
            
            # Check if expansions happen on the current tick
            expand_G = (tick % 2 == 0)
            expand_M = (tick % 7 == 0)
            
            # 1. Calculate potential Grass expansions
            if expand_G:
                for x, y in grass_front:
                    for dx, dy in [(-1,0), (1,0), (0,-1), (0,1)]:
                        nx, ny = x + dx, y + dy
                        if (nx, ny) not in grid:
                            next_G_front.add((nx, ny))
                            
            # 2. Calculate potential Mycelium expansions
            if expand_M:
                for x, y in myc_front:
                    for dx, dy in [(-1,0), (1,0), (0,-1), (0,1)]:
                        nx, ny = x + dx, y + dy
                        if (nx, ny) not in grid:
                            next_M_front.add((nx, ny))
                            
            # 3. Apply Grass first (resolves same-tick collisions in favor of Grass)
            if expand_G:
                grass_front = list(next_G_front)
                for nx, ny in grass_front:
                    grid[(nx, ny)] = 'G'
                    
            # 4. Apply Mycelium strictly to remaining empty tiles
            if expand_M:
                actual_M_front = []
                for nx, ny in next_M_front:
                    # Only convert if Grass didn't just take it
                    if (nx, ny) not in grid:
                        grid[(nx, ny)] = 'M'
                        actual_M_front.append((nx, ny))
                        myc_count += 1
                myc_front = actual_M_front
                
            tick += 1
            
        out.append(str(myc_count))
        
    print('\n'.join(out))

if __name__ == '__main__':
    solve()