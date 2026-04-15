from collections import deque

def solve():
    T = int(input())
    
    for _ in range(T):
        xg, yg, xm, ym = map(int, input().split())
        
        visited = {}
        
        q = deque()
        
        q.append((xg, yg, 0))
        q.append((xm, ym, 1))
        
        visited[(xg, yg)] = 0
        visited[(xm, ym)] = 1
        
        myc_count = 1  
        
        while q:
            x, y, owner = q.popleft()
            
            for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
                nx, ny = x + dx, y + dy
                
                if (nx, ny) not in visited:
                    visited[(nx, ny)] = owner
                    q.append((nx, ny, owner))
                    if owner == 1:
                        myc_count += 1
                else:
                    if owner == 0 and visited[(nx, ny)] == 1:
                        visited[(nx, ny)] = 0
        
        print(myc_count)

solve()
