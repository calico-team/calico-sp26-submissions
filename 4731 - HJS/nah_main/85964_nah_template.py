def solve(N, P, R, K, E):
    dylan_power = P
    defeated_count = 0
    
    for i in range(N):
        dylan_power -= E[i]
        
        if dylan_power < 0:
            return "nah i'd lose"
# BRO LOST LMAO            
        defeated_count += 1
        
        if defeated_count == K:
            dylan_power += R
            defeated_count = 0
            
    return "nah i'd win"

def read_your_input():
    import sys
    input_data = sys.stdin.read().split()
    if not input_data:
        return
        
    ptr = 0
    T_cases = int(input_data[ptr])
    ptr += 1
    
    for _ in range(T_cases):
        n_val = int(input_data[ptr])
        p_val = int(input_data[ptr+1])
        r_val = int(input_data[ptr+2])
        k_val = int(input_data[ptr+3])
        ptr += 4
        
        e_list = []
        for _ in range(n_val):
            e_list.append(int(input_data[ptr]))
            ptr += 1
            
        print(solve(n_val, p_val, r_val, k_val, e_list))

if __name__ == "__main__":
    read_your_input()