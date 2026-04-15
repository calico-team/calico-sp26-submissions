# at some t, there's the 
# x has some Q steps, and y has some P steps
#so we have like 2 lin eqs with the next x and y coords
import math

#asteroids = []
T = int(input())
for test in range(T):
    asteroids = [] 
    K, N,M, P, Q = map(int, input().split())
    for i in range(K):
        x,y = map(int, input().split())
        asteroids.append((x,y)) #tuple of coords
    
    #initTup = asteroids[0]
    initX, initY = asteroids[0] #initialx and initialy
    steps = math.lcm(N, M) #
    nowX, nowY = initX, initY
    final = 0
    fintup = (0,0)

    for step in range(steps):
        nowX = (nowX + Q) % N
        nowY = (nowY + P) % M
        for i in range(K):
            if (nowX, nowY) == asteroids[i]: #baxinga! lazer hit
                final = i
                break
            
            fintup = (nowX, nowY) #final tuple
        
        if final !=0 or fintup == (initX, initY):
            break
    
    print(final)
# plz work