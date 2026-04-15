T = int(input())

for _ in range(T):
    XG, YG, XM, YM = map(int, input().split())
    
    visited = set()
    stack = [(XM, YM)]
    visited.add((XM, YM))
    
    myc = 1
    
    LIMIT = 2500
    
    for i in range(len(stack)):
        x, y = stack[i]
        
        if abs(x - XM) + abs(y - YM) > LIMIT:
            continue
        
        for dx, dy in ((1,0), (-1,0), (0,1), (0,-1)):
            nx = x + dx
            ny = y + dy
            
            if (nx, ny) in visited:
                continue
            
            dM = abs(nx - XM) + abs(ny - YM)
            dG = abs(nx - XG) + abs(ny - YG)
            
            if 7 * dM < 2 * dG:
                visited.add((nx, ny))
                stack.append((nx, ny))
                myc += 1
    
    print(myc)
