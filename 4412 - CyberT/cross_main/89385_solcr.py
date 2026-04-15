import sys

def main():
    input_data = sys.stdin.read()
    lines = input_data.split('\n')
    # Remove trailing empty lines
    while lines and lines[-1].strip() == '':
        lines.pop()
    
    idx = 0
    t = int(lines[idx]); idx += 1
    
    out = []
    for _ in range(t):
        n = int(lines[idx]); idx += 1
        
        s1 = []
        for r in range(n):
            s1.append(lines[idx].strip()); idx += 1
        
        s2 = []
        for r in range(n):
            s2.append(lines[idx].strip()); idx += 1
        
        max_vol = 0
        min_vol = 0
        for r in range(n):
            s1_cols = s1[r].count('#')
            s2_deps = s2[r].count('#')
            max_vol += s1_cols * s2_deps
            min_vol += max(s1_cols, s2_deps)
        
        out.append(f"{max_vol} {min_vol}")
    
    print('\n'.join(out))

main()

def read_your_input():
    input_data = sys.stdin.read()
    lines = input_data.split('\n')
    while lines and lines[-1].strip() == '':
        lines.pop()
    idx = 0
    t = int(lines[idx]); idx += 1
    cases = []
    for _ in range(t):
        n = int(lines[idx]); idx += 1
        s1 = [lines[idx+i].strip() for i in range(n)]; idx += n
        s2 = [lines[idx+i].strip() for i in range(n)]; idx += n
        cases.append((n, s1, s2))
    return cases