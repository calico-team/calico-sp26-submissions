import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, p, r, k = map(int, input().split())
    arr = list(map(int, input().split()))
    
    power = p
    charges = 0
    ok = True
    
    for i in range(n):
        if power < arr[i]:
            while charges > 0 and power < arr[i]:
                power += r
                charges -= 1
            if power < arr[i]:
                ok = False
                break
        
        power -= arr[i]
        
        if (i + 1) % k == 0:
            charges += 1
    
    if ok:
        print("nah i'd win")
    else:
        print("nah i'd lose")