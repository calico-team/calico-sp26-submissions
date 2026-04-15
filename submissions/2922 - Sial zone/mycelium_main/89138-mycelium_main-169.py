T = int(input())

for _ in range(T):
    xg, yg, xm, ym = map(int, input().split())
    
    D = abs(xg - xm) + abs(yg - ym)
    
    ans = (D * D - D) // 2 + 1
    
    print(ans)