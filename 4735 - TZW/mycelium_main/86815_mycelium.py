T = int(input())

for _ in range(T):
    
    xg, yg, xm, ym = map(int, input().split())
    dx = xm - xg
    dy = ym - yg
    
    D = abs(dx) + abs(dy)
    max_dm = (2 * D - 1) // 5
    count = 1
    
    for dm in range(1, max_dm + 1):
        for a in range(-dm, dm + 1):
            b = dm - abs(a)
            
            for tb in ([b, -b] if b != 0 else [0]):
                dg = abs(a + dx) + abs(tb + dy)
                
                if 7 * dm < 2 * dg:
                    count += 1
                    
    print(count)
