T = int(input())

for _ in range(T):
    N = int(input())
    
    S1 = [input().strip() for _ in range(N)]
    S2 = [input().strip() for _ in range(N)]
    
    A = [0] * N
    B = [0] * N
    
    for x in range(N):
        for y in range(N):
            if S1[x][y] == '#':
                A[y] += 1
    
    for y in range(N):
        for z in range(N):
            if S2[y][z] == '#':
                B[y] += 1
    
    max_vol = 0
    min_vol = 0
    
    for y in range(N):
        max_vol += A[y] * B[y]
        min_vol += max(A[y], B[y])
    
    print(max_vol, min_vol)
