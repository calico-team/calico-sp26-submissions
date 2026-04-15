import sys

def solve():
    data = sys.stdin.read().splitlines()
    if not data:
        return
    
    idx = 0
    T = int(data[idx].strip())
    idx += 1
    
    for _ in range(T):
        N = int(data[idx].strip())
        idx += 1
        
        S1 = []
        for _ in range(N):
            S1.append(data[idx].strip())
            idx += 1
        
        S2 = []
        for _ in range(N):
            S2.append(data[idx].strip())
            idx += 1
        
        min_vol = 0
        max_vol = 0
        
        for z in range(N):
            # 统计该层 S1 和 S2 中 '#' 的数量
            cnt1 = sum(1 for x in range(N) if S1[z][x] == '#')
            cnt2 = sum(1 for y in range(N) if S2[z][y] == '#')
            
            min_vol += max(cnt1, cnt2)
            max_vol += cnt1 * cnt2
        
        print(max_vol, min_vol)
        

if __name__ == "__main__":
    solve()