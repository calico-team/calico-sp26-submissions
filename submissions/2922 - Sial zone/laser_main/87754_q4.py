T = int(input())

for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    asteroids = [tuple(map(int, input().split())) for _ in range(K)]
    
    start = asteroids[0]
    
    visited = {}
    x, y = start
    step = 0
    
    while (x, y) not in visited:
        visited[(x, y)] = step
        x = (x + Q) % N
        y = (y + P) % M
        step += 1
    
    cycle_len = step
    
    best = float('inf')
    ans = -1
    
    for i, (ax, ay) in enumerate(asteroids):
        if (ax, ay) in visited:
            t = visited[(ax, ay)]
            if t == 0:
                t = cycle_len
            if t < best:
                best = t
                ans = i
    
    print(ans)