T = int(input())

for _ in range(T):
    N = int(input())
    
    S1 = [input().strip() for _ in range(N)]
    S2 = [input().strip() for _ in range(N)]
    
    max_vol = 0
    min_vol = 0
    
    for z in range(N):
        
        a = S1[z].count('#')
        b = S2[z].count('#')
        
        max_vol += a * b
        min_vol += max(a, b)
        
    print(max_vol, min_vol)
