import sys
input = sys.stdin.readline

def solve(K, N, M, P, Q, asteroids):
    asteroid_set = {}
    for i, (x, y) in enumerate(asteroids):
        if (x, y) not in asteroid_set:
            asteroid_set[(x, y)] = i
    
    sx, sy = asteroids[0]
    x, y = sx, sy
    seen = set()
    
    while True:
        x = (x + Q) % N
        y = (y + P) % M
        if (x, y) in asteroid_set:
            return asteroid_set[(x, y)]
        if (x, y) in seen:
            break
        seen.add((x, y))

T = int(input())
for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    asteroids = []
    for _ in range(K):
        xi, yi = map(int, input().split())
        asteroids.append((xi, yi))
    print(solve(K, N, M, P, Q, asteroids))