T = int(input())

for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    
    asteroids = [tuple(map(int, input().split())) for _ in range(K)]
    
    start = asteroids[0]
    
    visited = dict()
    
    x, y = start
    step = 0
    
    while (x, y) not in visited:
        visited[(x, y)] = step
        x = (x + Q) % N
        y = (y + P) % M
        step += 1
    
    answer = float('inf')
    idx = -1
    
    for i in range(K):
        if asteroids[i] in visited:
            if visited[asteroids[i]] > 0 and visited[asteroids[i]] < answer:
                answer = visited[asteroids[i]]
                idx = i
    
    print(idx)