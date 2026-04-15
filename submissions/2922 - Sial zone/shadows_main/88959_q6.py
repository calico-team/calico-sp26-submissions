T = int(input())

for _ in range(T):
    N = int(input())
    
    S1 = [input().strip() for _ in range(N)]
    S2 = [input().strip() for _ in range(N)]
    
    max_vol = 0
    
    total_s1 = 0
    total_s2 = 0
    
    for z in range(N):
        cy = sum(1 for y in range(N) if S1[y][z] == '#')
        cx = sum(1 for x in range(N) if S2[x][z] == '#')
        
        max_vol += cy * cx
        total_s1 += cy
        total_s2 += cx
    
    min_vol = max(total_s1, total_s2)
    
    print(max_vol, min_vol)