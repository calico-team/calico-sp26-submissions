import sys

def solve():
    data = sys.stdin.buffer.read().split()
    idx = 0
    T = int(data[idx]); idx += 1
    
    out = []
    for _ in range(T):
        N = int(data[idx]); idx += 1
        
        # Read S1: N lines
        S1 = []
        for i in range(N):
            s = data[idx]
            if isinstance(s, bytes):
                s = s.decode()
            S1.append(s)
            idx += 1
        
        # Read S2: N lines
        S2 = []
        for i in range(N):
            s = data[idx]
            if isinstance(s, bytes):
                s = s.decode()
            S2.append(s)
            idx += 1
        
        max_vol = 0
        min_vol = 0
        
        for z in range(N):
            m = S1[z].count('#')
            n = S2[z].count('#')
            
            max_vol += m * n
            
            if m > 0 and n > 0:
                min_vol += max(m, n)
        
        out.append(f"{max_vol} {min_vol}")
    
    print('\n'.join(out))

if __name__ == "__main__":
    solve()