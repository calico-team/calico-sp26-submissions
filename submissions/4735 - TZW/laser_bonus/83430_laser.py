T = int(input())

for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    
    asteroids = {}
    points = []
    
    for i in range(K):
        x, y = map(int, input().split())
        asteroids[(x, y)] = i
        points.append((x, y))
    
    x, y = points[0]
    visited = set()
    
    while True:
        x = (x + Q) % N
        y = (y + P) % M
        
        if (x, y) in asteroids:
            print(asteroids[(x, y)])
            break
