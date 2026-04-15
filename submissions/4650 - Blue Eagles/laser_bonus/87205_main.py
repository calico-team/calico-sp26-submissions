t = int(input())

for test in range(t):
    line = input().split()
    k = int(line[0])
    n = int(line[1])
    m = int(line[2])
    p = int(line[3])
    q = int(line[4])
    
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
        steps = steps + 1
        
        x = (x + q) % n
        y = (y + p) % m
        
        for i in range(k):
            ax = asteroids[i][0]
            ay = asteroids[i][1]
            if ax == x and ay == y:
                if i != 0 or steps > 1:
                    answer = i
                    break
        
        if answer != -1:
            break
        
        if x == start_x and y == start_y and steps > 1:
            break
    
    print(answer)