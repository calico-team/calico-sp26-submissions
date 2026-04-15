t = int(input())  

for _ in range(t):
    n, p, r, k = map(int, input().split())
    curses = list(map(int, input().split()))
    
    power = p
    defeated = 0
    lose = False
    
    for curse_power in curses:
        
        if defeated > 0 and defeated % k == 0:
            power += r
        
        if power >= curse_power:
            
            power -= curse_power
            defeated += 1
        else:
           
            lose = True
            break
    
    if lose:
        print("nah i'd lose")
    else:
        print("nah i'd win")