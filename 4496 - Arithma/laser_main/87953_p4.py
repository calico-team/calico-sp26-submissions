T = int(input().strip())

for j in range(T):
    K, N, M, P, Q = map(int, input().split())
    
    asteroids = []
    pos_map = {}
    
    for i in range(K):
        x, y = map(int, input().split())
        asteroids.append((x, y))
        pos_map[(x, y)] = i

    x, y = asteroids[0]
    visited = set()
    lazarbeam = 0  
    while True:
        x = (x + Q) % N
        y = (y + P) % M
        
        if (x, y) in visited:
            break
        visited.add((x, y))
        
        if (x, y) in pos_map:
            print(pos_map[(x, y)])
            break