def solve(K, N, M, P, Q, asteroids):
    
    pos_to_idx = {}
    for i, (x, y) in enumerate(asteroids):
        pos_to_idx[(x, y)] = i
    
    x, y = asteroids[0]
    
    max_steps = N * M
    
    for step in range(1, max_steps + 1):
        # Move laser
        x = (x + Q) % N
        y = (y + P) % M
        
        # Check if we hit an asteroid
        if (x, y) in pos_to_idx:
            return pos_to_idx[(x, y)]
    
    return -1

# Read input
T = int(input())
for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    asteroids = []
    for _ in range(K):
        x, y = map(int, input().split())
        asteroids.append((x, y))
    
    result = solve(K, N, M, P, Q, asteroids)
    print(result)