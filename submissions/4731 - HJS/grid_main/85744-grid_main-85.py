def solve(N, A):
    the_two_tower_heights = []
    for height in A:
        the_two_tower_heights.append(height)
    
    return the_two_tower_heights

def read_your_input():
    import sys
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    idx = 0
    t_cases = int(input_data[idx])
    idx += 1
    
    for _ in range(t_cases):
        n_val = int(input_data[idx])
        idx += 1
        
        a_row = []
        for _ in range(n_val):
            a_row.append(int(input_data[idx]))
            idx += 1
            
        ans = solve(n_val, a_row)
        print(*(ans))

if __name__ == '__main__':
    read_your_input()