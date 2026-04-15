t = int(input())

for _ in range(t):
    total_battles, starting_power, power_boost, boost_after = map(int, input().split())
    enemy_hits = list(map(int, input().split()))
    
    my_power = starting_power
    fights_done = 0
    still_alive = True
    
    for hit in enemy_hits:
        my_power -= hit
        
        if my_power < 0:
            still_alive = False
            break
        
        fights_done += 1
        
        if fights_done % boost_after == 0:
            my_power += power_boost
    
    print("nah i'd win" if still_alive else "nah i'd lose")