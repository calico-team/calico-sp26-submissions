def censor_this_please(A, B):
    res = []
    b_idx = 0
    for char in A:
        if b_idx < len(B) and char == B[b_idx]:
            res.append(char)
            b_idx += 1
        else:
            res.append('#')
            
    return "".join(res)

def solve(A, B):
    return censor_this_please(A, B)

def read_your_input():
    import sys
    lines = [line.strip() for line in sys.stdin.readlines() if line.strip()]
    if not lines:
        return
        
    t_cases = int(lines[0])
    current_line = 1
    
    for _ in range(t_cases):
        a_str = lines[current_line]
        b_str = lines[current_line + 1]
        
        print(solve(a_str, b_str))
        current_line += 2

if __name__ == '__main__':
    read_your_input()