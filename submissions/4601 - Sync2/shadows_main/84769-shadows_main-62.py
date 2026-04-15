import sys

def main():
    input_data = sys.stdin.read().split('\n')
    idx = 0
    
    while idx < len(input_data) and input_data[idx].strip() == '':
        idx += 1
    
    t = int(input_data[idx].strip()); idx += 1
    
    for _ in range(t):
        # skip blank lines
        while idx < len(input_data) and input_data[idx].strip() == '':
            idx += 1
        
        n = int(input_data[idx].strip()); idx += 1
        
        s1 = []
        for i in range(n):
            while idx < len(input_data) and input_data[idx].strip() == '':
                idx += 1
            s1.append(input_data[idx].strip())
            idx += 1
        
        s2 = []
        for i in range(n):
            while idx < len(input_data) and input_data[idx].strip() == '':
                idx += 1
            s2.append(input_data[idx].strip())
            idx += 1
        
        ans_max = 0
        ans_min = 0
        
        for z in range(n):
            cx = s1[z].count('#')
            cy = s2[z].count('#')
            ans_max += cx * cy
            if cx > 0 and cy > 0:
                ans_min += max(cx, cy)
        
        print(ans_max, ans_min)

main()

def read_your_input():
    lines = sys.stdin.read().split('\n')
    return [l.strip() for l in lines if l.strip()]