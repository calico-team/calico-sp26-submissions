t = int(input())

for test in range(t):
    stuff = input().split()
    k = int(stuff[0])
    n = int(stuff[1])
    m = int(stuff[2])
    p = int(stuff[3])
    q = int(stuff[4])

    asteroids = []
    for i in range(k):
        line = input().split()
        x = int(line[0])
        y = int(line[1])
        asteroids.append((x, y))

    start_x = asteroids[0][0]
    start_y = asteroids[0][1]

    x = start_x
    y = start_y
    answer = -1
    steps = 0

    while True:
        step = steps + 1

        x = (x + q) % n
        y = (y + p) % m

        for i in range(k):
            if asteroids[i][0] == x and asteroids[i][1] == y:
                if i != 0 or steps > 1:
                    answer = i
                    break
        
        if answer != -1:
            break
        
        if x== start_x and y == start_y and steps > 1:
            break

    print(answer)