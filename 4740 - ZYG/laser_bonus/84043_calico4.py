T = int(input())
for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    
    asteroids = []
    pos_to_index = {}
    
    for i in range(K):
        x, y = map(int, input().split())
        asteroids.append((x, y))
        pos_to_index[(x, y)] = i
    
    cur_x, cur_y = asteroids[0]
    
    while True:
        cur_x = (cur_x + Q) % N
        cur_y = (cur_y + P) % M
        
        if (cur_x, cur_y) in pos_to_index:
            print(pos_to_index[(cur_x, cur_y)])
            break

