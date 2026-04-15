def solve():
    import sys
    input = sys.stdin.read().split()
    idx = 0
    T = int(input[idx])
    idx += 1
    for _ in range(T):
        N = int(input[idx])
        P = int(input[idx+1])
        R = int(input[idx+2])
        K = int(input[idx+3])
        idx += 4
        
        E = list(map(int, input[idx:idx+N]))
        idx += N
        
        current_power = P
        defeated = 0
        charges_available = 0
        can_win = True
        
        for i in range(N):
            curse = E[i]
            
            while current_power < curse and charges_available > 0:
                current_power += R
                charges_available -= 1
            
            if current_power < curse:
                can_win = False
                break
            
            current_power -= curse
            defeated += 1
            
            if defeated % K == 0:
                charges_available += 1
        
        if can_win:
            print("nah i'd win")
        else:
            print("nah i'd lose")

if __name__ == "__main__":
    solve()
