from math import ceil

first_input = int(input())

for a in range(first_input):

    info = list(map(int,input().split(' ')))

    asteroids = []
    asteroid_x_coords = []
    asteroid_x_coords_with_index = {}
    asteroid_y_coords = []

    for b in range(info[0]):
        asteroids.append(list(map(int,input().split(' '))))

        if asteroids[b][0] not in asteroid_x_coords:
            asteroid_x_coords.append(asteroids[b][0])
        
        if asteroids[b][0] not in asteroid_x_coords_with_index:
            asteroid_x_coords_with_index[asteroids[b][0]] = []

        asteroid_x_coords_with_index[asteroids[b][0]].append(b)

    asteroid = asteroids[0].copy()

    asteroid_x_coords.sort()

    for a in range(info[0]):

        if asteroid_x_coords[0] <= asteroid[0]:
            asteroid_x_coords.append(asteroid_x_coords[0])
            asteroid_x_coords.pop(0)

    found = False

    while True:

        for f in asteroid_x_coords:

            if (f-asteroid[0]) % info[4] == 0:
                for g in asteroid_x_coords_with_index[f]:

                    if (asteroids[g][1] - asteroid[1]) % info[3] == 0:
                        found = True
                        print(g)
                        break

            if found == True:
                break
        
        if found == True:
            break

        steps = min( ceil( (info[1]-asteroid[0]) / info[4] ) , ceil( (info[2]-asteroid[1]) / info[3] ) )

        asteroid = [ (asteroid[0]+steps*info[4])%info[1] , (asteroid[1]+steps*info[3])%info[2] ]

        if asteroid == asteroids[0]:
            print(0)
            break