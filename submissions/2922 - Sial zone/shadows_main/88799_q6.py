T = int(input())

for _ in range(T):
    N = int(input())
    
    S1 = [input().strip() for _ in range(N)]
    S2 = [input().strip() for _ in range(N)]
    
    max_vol = 0
    min_vol = 0
    
    for z in range(N):
        cy = sum(1 for y in range(N) if S1[y][z] == '#')
        cx = sum(1 for x in range(N) if S2[x][z] == '#')
        
        max_vol += cy * cx
        min_vol += max(cy, cx)
    
    print(max_vol, min_vol)