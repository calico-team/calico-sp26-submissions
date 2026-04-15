T = int(input())

for _ in range(T):
    XG, YG, XM, YM = map(int, input().split())
    
    grass = {(XG, YG)}
    myc = {(XM, YM)}
    
    visited_g = {(XG, YG)}
    visited_m = {(XM, YM)}
    
    for t in range(1, 60):
        
        if t % 2 == 0:
            new_g = set()
            for x, y in grass:
                for dx, dy in ((1,0), (-1,0), (0,1), (0,-1)):
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in visited_g:
                        visited_g.add((nx, ny))
                        new_g.add((nx, ny))
            grass |= new_g
        
        if t % 7 == 0:
            new_m = set()
            for x, y in myc:
                for dx, dy in ((1,0), (-1,0), (0,1), (0,-1)):
                    nx, ny = x + dx, y + dy
                    if (nx, ny) not in visited_m:
                        visited_m.add((nx, ny))
                        new_m.add((nx, ny))
            myc |= new_m
        
        myc -= grass
    
    print(len(myc))
