first_input = int(input())

for a in range(first_input):

    info = list(map(int,input().split(' ')))

    asteroids = []

    for b in range(info[0]):
        asteroids.append(list(map(int,input().split(' '))))

    asteroid = asteroids[0].copy()

    while True:
        asteroid[0] += info[4]
        asteroid[1] += info[3]
        asteroid[0] = asteroid[0] % info[1]
        asteroid[1] = asteroid[1] % info[2]

        if asteroid in asteroids:
            print(asteroids.index(asteroid))
            break