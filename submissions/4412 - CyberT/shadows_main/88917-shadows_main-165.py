import sys

def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    
    out = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        
        s1 = []
        for r in range(n):
            s1.append(data[idx]); idx += 1
        
        s2 = []
        for r in range(n):
            s2.append(data[idx]); idx += 1
        
        max_vol = 0
        min_vol = 0
        for r in range(n):
            s1_cols = s1[r].count(ord('#'))
            s2_deps = s2[r].count(ord('#'))
            max_vol += s1_cols * s2_deps
            min_vol += max(s1_cols, s2_deps)
        
        out.append(f"{max_vol} {min_vol}")
    
    sys.stdout.write('\n'.join(out) + '\n')

main()

def read_your_input():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    cases = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        s1 = [data[idx+i] for i in range(n)]; idx += n
        s2 = [data[idx+i] for i in range(n)]; idx += n
        cases.append((n, s1, s2))
    return cases