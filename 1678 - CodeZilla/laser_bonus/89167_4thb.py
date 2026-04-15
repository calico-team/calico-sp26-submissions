import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    n, p, r, k = map(int, input().split())
    arr = list(map(int, input().split()))
    
    power = p
    charges = 0
    ok = True
    
    for j in range(n):
        
        if power >= arr[j]:
            power = power - arr[j]
        else:
            while charges > 0:
                power = power + r
                charges = charges - 1
                if power >= arr[j]:
                    break
            
            if power >= arr[j]:
                power = power - arr[j]
            else:
                ok = False
                break
        
        if (j + 1) % k == 0:
            charges = charges + 1
    
    print("nah i'd win" if ok else "nah i'd lose")