import sys

def main():
    input = sys.stdin.read().splitlines()
    idx = 0
    t = int(input[idx]); idx += 1
    out = []
    
    for _ in range(t):
        n = int(input[idx]); idx += 1
        
        s1 = input[idx:idx+n]; idx += n
        s2 = input[idx:idx+n]; idx += n
        
        max_vol = 0
        min_vol = 0
        for r in range(n):
            a = s1[r].count('#')
            b = s2[r].count('#')
            max_vol += a * b
            min_vol += a if a > b else b
        
        out.append(f"{max_vol} {min_vol}")
    
    sys.stdout.write('\n'.join(out) + '\n')

main()

def read_your_input():
    lines = sys.stdin.read().splitlines()
    idx = 0
    t = int(lines[idx]); idx += 1
    cases = []
    for _ in range(t):
        n = int(lines[idx]); idx += 1
        s1 = lines[idx:idx+n]; idx += n
        s2 = lines[idx:idx+n]; idx += n
        cases.append((n, s1, s2))
    return cases