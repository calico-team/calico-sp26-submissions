t = int(input())
for _ in range(t):
    k, n, m, p, q = map(int, input().split())

    

    asteroids = {}

    for i in range(k):
        
        x1, y1 = map(int, input().split())
        if i == 0:
            x, y = x1, y1
        asteroids[(x1, y1)] = i

    ans = -1
    #depth = 0
    while True:
        #depth += 1
        #print(x, y)
        x += q
        y += p 

        x = x % n
        y = y % m

        if (x, y) in asteroids:
            ans = asteroids[(x, y)]
            break
        
        
    

    print(ans)