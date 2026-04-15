T = int(input())

for _ in range(T):
    XG, YG, XM, YM = map(int, input().split())
    
    dx = abs(XG - XM)
    dy = abs(YG - YM)
    
    R = 4 * (dx + dy) + 5
    
    count = 0
    
    for x in range(min(XG, XM) - R, max(XG, XM) + R + 1):
        for y in range(min(YG, YM) - R, max(YG, YM) + R + 1):
            
            dG = abs(x - XG) + abs(y - YG)
            dM = abs(x - XM) + abs(y - YM)
            
            if 7 * dM < 2 * dG:
                count += 1
    
    print(count)
