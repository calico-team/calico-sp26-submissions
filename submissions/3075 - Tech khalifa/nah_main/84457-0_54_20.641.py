T = int(input())

for _ in range(T):
    N, P, R, K = map(int, input().split())
    enemies = list(map(int, input().split()))
    
    power = P
    count = 0
    alive = True
    
    for e in enemies:
        power -= e
        count += 1
        
        if power < 0:
            alive = False
            break
        
        if count % K == 0:
            power += R
    
    if alive:
        print("nah i'd win")
    else:
        print("nah i'd lose")