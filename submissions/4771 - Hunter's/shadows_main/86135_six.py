import sys

def solve():
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    
    t = int(input_data[0])
    idx = 1
    results = []
    
    for _ in range(t):
        N = int(input_data[idx]); idx += 1
        
        S1 = []
        for __ in range(N):
            S1.append(input_data[idx]); idx += 1
        
        S2 = []
        for __ in range(N):
            S2.append(input_data[idx]); idx += 1
        max_vol = 0
        for y in range(N):
            for z in range(N):
                if S1[y][z] == '#':
                    for x in range(N):
                        if S2[x][z] == '#':
                            max_vol += 1
        min_vol = 0
        for z in range(N):
            cnt1 = sum(1 for y in range(N) if S1[y][z] == '#')
            cnt2 = sum(1 for x in range(N) if S2[x][z] == '#')
            min_vol += max(cnt1, cnt2)
        
        results.append(f"{max_vol} {min_vol}")
    
    sys.stdout.write("\n".join(results))

def read_your_input():
    solve()

if __name__ == "__main__":
    solve()