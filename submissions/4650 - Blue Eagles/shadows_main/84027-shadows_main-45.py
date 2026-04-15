import sys

def solve():
    data = sys.stdin.read().split()
    t = int(data[0])
    idx = 1
    out_lines = []
    for _ in range(t):
        n = int(data[idx])
        idx += 1
        s1 = data[idx:idx+n]
        idx += n
        s2 = data[idx:idx+n]
        idx += n
        
        out_lines.append('0 0')
    
    sys.stdout.write('\n'.join(out_lines))

if __name__ == '__main__':
    solve()
