for _ in range(int(input())):
    K,N,M,P,Q = map(int,input().split())
    asteroids = {}
    laserS = [0,0]
    for i in range(K):
        x, y = map(int, input().split())
        asteroids[(x, y)] = i
        if i == 0: laserS = [x,y]
    hit = False
    ans = None
    while not hit:
        laserS[0] = (laserS[0] + Q) % N
        laserS[1] = (laserS[1] + P) % M
        if tuple(laserS) in asteroids:
            hit = True
            ans = asteroids[tuple(laserS)]
            break
    print(ans)