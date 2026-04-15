T = int(input())

for _ in range(T):
    N, P, R, K = map(int, input().split())
    curses = list(map(int, input().split()))
    
    dylan_power = P
    count = 0
    lost = False
    
    for i in range(N):
        dylan_power -= curses[i]
        
        if dylan_power < 0:
            lost = True
            break
        
        count += 1
        
        if count % K == 0:
            dylan_power += R
    
    if lost:
        print("nah i'd lose")
    else:
        print("nah i'd win")

def read_your_input():
    return map(int, input().split())