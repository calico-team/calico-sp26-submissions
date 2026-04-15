n=int(input())
for i in range(n):
    knmpq=input().split()
    k=int(knmpq[0])
    n=int(knmpq[1])
    m=int(knmpq[2])
    p=int(knmpq[3])
    q=int(knmpq[4])
    asteroids=[]
    for j in range(k):
        laser=input().split()
        laserx=int(laser[0])
        lasery=int(laser[1])
        asteroids.append([laserx,lasery])
    laserx=asteroids[0][0]
    lasery=asteroids[0][1]
    asteRAID=-1
    for j in range(n*m+1):
        laserx=(laserx+q)%n
        lasery=(lasery+p)%m
        for h in range(k):
            if laserx==asteroids[h][0] and lasery==asteroids[h][1]:
                asteRAID=h
                break
        if asteRAID!=-1:
            break 
    print(asteRAID)
