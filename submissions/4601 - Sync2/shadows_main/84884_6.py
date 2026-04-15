import sys

def solve():
    input = sys.stdin.buffer.read().split()
    idx = 0
    T = int(input[idx]); idx += 1
    
    out = []
    for _ in range(T):
        N = int(input[idx]); idx += 1
        
        S1 = []
        for i in range(N):
            S1.append(input[idx].decode() if isinstance(input[idx], bytes) else input[idx])
            idx += 1
        
        S2 = []
        for i in range(N):
            S2.append(input[idx].decode() if isinstance(input[idx], bytes) else input[idx])
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