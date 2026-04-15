for _ in range(int(input())):
    N = int(input())
    S1 = [list(input()) for _ in range(N)]
    S2 = [list(input()) for _ in range(N)]
    
    max_blocks = 0
    min_blocks = 0
    
    for i in range(N):
        c1 = 0
        c2 = 0
        for j in range(N):
            if S1[i][j] == "#":
                c1 += 1
            if S2[i][j] == "#":
                c2 += 1
                
        max_blocks += c1 * c2
        min_blocks += max(c1, c2)
    
    print(max_blocks, min_blocks)