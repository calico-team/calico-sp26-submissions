import sys
input = sys.stdin.readline

numCasesStr = input()
if numCasesStr:
    numCases = int(numCasesStr)
    
    for _ in range(numCases):
        k, n, m, p, q = map(int, input().split())
        ptsX = [0] * k
        ptsY = [0] * k
        
        for i in range(k):
            ptsX[i], ptsY[i] = map(int, input().split())
            
        startX = ptsX[0]
        startY = ptsY[0]
        minVal = -1
        ansIdx = -1
        
        for i in range(k):
            dx = (ptsX[i] - startX + n) % n
            dy = (ptsY[i] - startY + m) % m
            
            a, b, x, y = q, n, 1, 0
            while b:
                qt = a // b
                a, b = b, a % b
                x, y = y, x - qt * y
                
            if dx % a != 0:
                continue
            mx = n // a
            rx = ((dx // a) * (x % mx)) % mx
            
            a, b, x, y = p, m, 1, 0
            while b:
                qt = a // b
                a, b = b, a % b
                x, y = y, x - qt * y
                
            if dy % a != 0:
                continue
            my = m // a
            ry = ((dy // a) * (x % my)) % my
            
            a, b, x, y = mx, my, 1, 0
            while b:
                qt = a // b
                a, b = b, a % b
                x, y = y, x - qt * y
                
            diff = ry - rx
            if diff % a != 0:
                continue
                
            myg = my // a
            diff = (diff // a) % myg
            x = x % myg
            kt = (diff * x) % myg
            
            cur = rx + kt * mx
            period = mx * myg
            
            if cur == 0:
                cur += period
                
            if minVal == -1 or cur < minVal:
                minVal = cur
                ansIdx = i
                
        sys.stdout.write(f"{ansIdx}\n")