T = int(input())

for _ in range(T):
    XG, YG, XM, YM = map(int, input().split())
    
    ax = XG - XM
    ay = YG - YM
    
    R = 2 * (abs(ax) + abs(ay)) + 5
    
    count = 0
    
    for x in range(XM - R, XM + R + 1):
        for y in range(YM - R, YM + R + 1):
            
            dM = abs(x - XM) + abs(y - YM)
            dG = abs(x - XG) + abs(y - YG)
            
            if 7 * dM < 2 * dG:
                count += 1
    
    print(count)
