import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    t = int(input_data[0])
    idx = 1
    results = []
    
    for _ in range(t):
        N = int(input_data[idx])
        P = int(input_data[idx+1])
        R = int(input_data[idx+2])
        K = int(input_data[idx+3])
        idx += 4
        
        E = list(map(int, input_data[idx:idx+N]))
        idx += N
        
        curr_power = P
        defeated = 0
        win = True
        
        for e in E:
            curr_power -= e
            if curr_power < 0:
                win = False
                break
            
            defeated += 1
            if defeated % K == 0:
                curr_power += R
                dylan_power = curr_power
                
        results.append("nah i'd win" if win else "nah i'd lose")
        
    sys.stdout.write("\n".join(results))

def read_your_input():
    pass

if __name__ == '__main__':
    solve()
    read_your_input()