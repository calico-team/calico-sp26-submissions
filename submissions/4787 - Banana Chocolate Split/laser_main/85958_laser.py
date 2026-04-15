import math

t = int(input())
for _ in range(t):
    num, n, m, rise, run = map(int, input().split())
    asteroids = list()
    for _ in range(num):
        slope = rise / run
        asteroid_hit = False
        asteroid_n = list(map(int, input().split()))
        asteroids.append(asteroid_n)

    x = asteroids[0][0]
    y = asteroids[0][1]
    skip = False
    while asteroid_hit == False:
        for i in range(0, num):
            if skip == False:
                skip = True
                continue
            skip = True
            if asteroids[i][1] - y == slope * (asteroids[i][0] - x):
                asteroid_hit = True
                print(i)
                break

        y_bound = math.ceil((m-y) / rise) 
        x_bound = math.ceil((n-x) / run)
        if y_bound <= x_bound: #wraps from the top to bottom
            x += y_bound * run
            y = y_bound * rise + y - m

        else: # wraps from the right to left
            y += x_bound * rise
            x = x_bound * run + x - n