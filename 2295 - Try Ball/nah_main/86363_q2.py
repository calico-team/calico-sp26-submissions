def solve():
    dylan_power = 0  

    T = int(input())
    
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        
        power = P
        win = True
        
        for i in range(N):
            power -= E[i]
            
            if power < 0:
                win = False
                break
            
            
            if (i + 1) % K == 0:
                power += R
        
        if win:
            print("nah i'd win")
        else:
            print("nah i'd lose")

solve()