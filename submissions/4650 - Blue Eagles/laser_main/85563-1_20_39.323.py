t = int(input())
for case in range(t):
    line = input().split()
    k = int(line[0])
    n = int(line[1])
    m = int(line[2])
    p = int(line[3])
    q = int(line[4])

    asteroids = []
    pos_to_index = {}

    for i in range(k):
        line = input().split()
        x = int(line[0])
        y = int(line[1])
        asteroids.append((x, y))
        pos_to_index[(x, y)] = i

    sx, sy = asteroids[0]
    x = sx
    y = sy
    step = 0
    hit_index = -1

    while True:
        step += 1
        x = (x + q) % n
        y = (y + p) % m

        if (x, y) in pos_to_index:
            idx = pos_to_idex[(x, y)]
            if idx != 0 or step % (n * m) != 0:
                hit_index = idx
                break
        if x == sx and y == sy and step > 1:
            break

    print(hit_index)