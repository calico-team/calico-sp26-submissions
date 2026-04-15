T = int(input())

for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    
    asteroids = []
    position = {}
    
    i = 0
    while i < K:
        line = input().strip()
        
        if len(line.split()) != 2:
            continue
        
        x, y = map(int, line.split())
        
        asteroids.append((x, y))
        position[(x, y)] = i
        i += 1
    
    x, y = asteroids[0]
    
    while True:
        x = (x + Q) % N
        y = (y + P) % M
        
        if (x, y) in position:
            print(position[(x, y)])
            break
