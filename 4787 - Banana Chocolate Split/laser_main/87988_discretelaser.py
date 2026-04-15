import math

t = int(input())
for _ in range(t):
    num, n, m, rise, run = map(int, input().split())
    asteroids = list()
    for _ in range(num):
        asteroid_n = list(map(int, input().split()))
        asteroids.append(asteroid_n)

    x = asteroids[0][0]
    y = asteroids[0][1]
    skip = False
    asteroid_hit = False
    while asteroid_hit == False:
        if y >= m:
            y = y - m
        if x >= n:
            x = x - n
        if [x,y] in asteroids:
            if skip == False:
                skip = True
                x = x + run
                y = y + rise
                continue
            else:
                asteroid_hit = True
                print(asteroids.index([x,y]))
                break

        x = x + run
        y = y + rise

