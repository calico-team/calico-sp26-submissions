T = int(input())
for _ in range(T):
    N, P, R, K = map(int, input().split())
    energy_arr = list(map(int, input().split()))
    
    running_P = P
    defeated = 0
    regen = 0
    possible = True
    
    for energy in energy_arr:
        running_P -= energy
        defeated += 1
        if defeated % K == 0:
            regen += 1
        if running_P < 0:
            if regen > 0:
                running_P += R
                regen -= 1
            else:
               possible = False
    
    if possible:
        print("nah i'd win")
    else:
        print("nah i'd lose") 
            
        
        