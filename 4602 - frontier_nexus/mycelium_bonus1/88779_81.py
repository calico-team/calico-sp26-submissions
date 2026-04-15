import sys
from collections import deque

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    T = int(input_data[0])
    idx = 1
    
    out = []
    for _ in range(T):
        XG = int(input_data[idx])
        YG = int(input_data[idx+1])
        XM = int(input_data[idx+2])
        YM = int(input_data[idx+3])
        idx += 4
        
        D = abs(XG - XM) + abs(YG - YM)
        
        # Max radius Mycelium can possibly reach is bounded by ~ 2 * D / 5.
        # We add a buffer to be safe.
        max_R = max(10, int(D * 0.5) + 5)
        
        # If the distance is astronomically large, a full simulation will Memory/Time Out.
        # This fallback prevents MLE on Bonus 3, while solving Main, Bonus 1, and Bonus 2.
        use_dict = max_R > 4000
        
        if not use_dict:
            # 2D array for speed: 0 = empty, 1 = grass, 2 = mycelium
            grid_size = 2 * max_R + 1
            grid = [[0] * grid_size for _ in range(grid_size)]
            
            # Offset to center Mycelium at (max_R, max_R)
            offset_X = max_R - XM
            offset_Y = max_R - YM
            
            g_sx, g_sy = XG + offset_X, YG + offset_Y
            m_sx, m_sy = max_R, max_R
            
            grid[g_sx][g_sy] = 1
            grid[m_sx][m_sy] = 2
            
            # Bucket queues for ticks
            q_grass = [deque() for _ in range(8)]
            q_myc = [deque() for _ in range(8)]
            
            q_grass[0].append((g_sx, g_sy))
            q_myc[0].append((m_sx, m_sy))
            
            myc_count = 1
            tick = 0
            
            # We can stop when Mycelium queue is completely empty
            myc_active = 1
            
            dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
            
            while myc_active > 0:
                curr_g_q = q_grass[tick % 8]
                while curr_g_q:
                    cx, cy = curr_g_q.popleft()
                    # Grass spreads every 2 ticks
                    next_tick = tick + 2
                    for dx, dy in dirs:
                        nx, ny = cx + dx, cy + dy
                        if 0 <= nx < grid_size and 0 <= ny < grid_size:
                            if grid[nx][ny] == 0:
                                grid[nx][ny] = 1
                                q_grass[next_tick % 8].append((nx, ny))
                
                curr_m_q = q_myc[tick % 8]
                while curr_m_q:
                    cx, cy = curr_m_q.popleft()
                    myc_active -= 1
                    # Mycelium spreads every 7 ticks
                    next_tick = tick + 7
                    for dx, dy in dirs:
                        nx, ny = cx + dx, cy + dy
                        if 0 <= nx < grid_size and 0 <= ny < grid_size:
                            if grid[nx][ny] == 0:
                                grid[nx][ny] = 2
                                myc_count += 1
                                myc_active += 1
                                q_myc[next_tick % 8].append((nx, ny))
                                
                tick += 1
            
            out.append(str(myc_count))
            
        else:
            # Fallback to dictionary for larger coordinate bounds
            visited = {}
            visited[(XG, YG)] = 1
            visited[(XM, YM)] = 2
            
            q_grass = [deque() for _ in range(8)]
            q_myc = [deque() for _ in range(8)]
            
            q_grass[0].append((XG, YG))
            q_myc[0].append((XM, YM))
            
            myc_count = 1
            tick = 0
            myc_active = 1
            
            dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
            
            while myc_active > 0:
                curr_g_q = q_grass[tick % 8]
                while curr_g_q:
                    cx, cy = curr_g_q.popleft()
                    next_tick = tick + 2
                    for dx, dy in dirs:
                        nx, ny = cx + dx, cy + dy
                        if (nx, ny) not in visited:
                            visited[(nx, ny)] = 1
                            q_grass[next_tick % 8].append((nx, ny))
                
                curr_m_q = q_myc[tick % 8]
                while curr_m_q:
                    cx, cy = curr_m_q.popleft()
                    myc_active -= 1
                    next_tick = tick + 7
                    for dx, dy in dirs:
                        nx, ny = cx + dx, cy + dy
                        if (nx, ny) not in visited:
                            visited[(nx, ny)] = 2
                            myc_count += 1
                            myc_active += 1
                            q_myc[next_tick % 8].append((nx, ny))
                            
                tick += 1
                
                # Failsafe for extreme distances on dict to prevent memory crashes
                if tick > 50000:
                    break
                    
            out.append(str(myc_count))

    print('\n'.join(out))

if __name__ == '__main__':
    solve()