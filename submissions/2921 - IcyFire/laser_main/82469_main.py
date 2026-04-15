def solve():
    K, N, M, P, Q = map(int, input().split())

    asteroids = set()
    asteroidsList = []

    laser = []

    for i in range(K):
        x, y = map(int, input().split())
        asteroids.add((x, y))
        asteroidsList.append([x, y])
        if len(laser) == 0:
            laser = [x, y]
    
    while True:
        laser[0] += P
        laser[1] += Q
        if (laser[0], laser[1]) in asteroids:
            print(asteroidsList.index(laser))
            return
    

for i in range(int(input())):
    solve()