import sys
input = sys.stdin.readline

t = int(input())

for i in range(t):
    n, P, R, K = map(int, input().split())
    E = list(map(int, input().split()))
    
    dylan_power = P
    uses = 0
    ok = True
    
    for j in range(n):
        
        if dylan_power >= E[j]:
            dylan_power = dylan_power -  E[j]
        else:
            while uses > 0:
                dylan_power = dylan_power + R
                uses = uses - 1
                if dylan_power >= E[j]:
                    break
            
            if dylan_power >= E[j]:
                dylan_power = dylan_power - E[j]
            else:
                ok = False
                break
        
        if (j + 1) % K == 0:
            uses = uses +1
    
    print("nah i'd win" if ok else "nah i'd lose")