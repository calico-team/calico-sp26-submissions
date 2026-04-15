T = int(input())

for _ in range(T):
    
    xg, yg, xm, ym = map(int, input().split())
    D = abs(xg - xm) + abs(yg - ym)
    
    if D == 0:
        print(0)
        continue
    
    max_dm = (2 * D - 1) // 5
    count = 1
    
    for dm in range(1, max_dm + 1):
        need_dg = 7 * dm // 2 + 1
        
        for a in range(-dm, dm + 1):
            b1 = dm - abs(a)
            
            for b in ([b1, -b1] if b1 > 0 else [0]):
                x = xm + a
                y = ym + b
                dg = abs(x - xg) + abs(y - yg)
                if 7 * dm < 2 * dg:
                    count += 1
                    
    print(count)
