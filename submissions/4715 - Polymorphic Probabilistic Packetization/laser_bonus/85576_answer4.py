import sys

line = sys.stdin.readline().split()

if line:
    T = int(line[0])
    for _ in range(T):
        p = sys.stdin.readline().split()
        if not p:
            break
        K, N, M, P, Q = map(int, p)
        a_map = {}
        start_x, start_y = -1, -1
        for i in range(K):
            coords = sys.stdin.readline().split()
            x, y = int(coords[0]), int(coords[1])
            if i == 0:
                start_x, start_y = x, y
            if (x, y) not in a_map:
                a_map[(x, y)] = i
        
        curr_x, curr_y = start_x, start_y
        ans = -1
        
    
        for step in range(1, N * M + 1):
            curr_x = (curr_x + Q) % N
            curr_y = (curr_y + P) % M
            
            
            if (curr_x, curr_y) in a_map:
                ans = a_map[(curr_x, curr_y)]
                break
        
   
        print(ans)