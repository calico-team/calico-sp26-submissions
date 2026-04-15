T = int(input())

for i in range(T):
    N, P, R, K = map(int, input().split())
    monsters = list(map(int, input().split()))
    
    hp = P          
    count = 0       
    win = True      
    
    for attack in monsters:
        if hp < attack:
            win = False
            break
        
        hp = hp - attack
        count = count + 1
        
        if count % K == 0:
            hp = hp + R
    
    if win:
        print("nah i'd win")
    else:
        print("nah i'd lose")