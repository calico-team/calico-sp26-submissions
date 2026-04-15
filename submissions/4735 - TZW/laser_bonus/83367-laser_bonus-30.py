def mod_number(a, mod):
    a %= mod
    for i in range(mod):
        if (a * i) % mod == 1:
            return i
    return -1

#------main------

T = int(input())

for _ in range(T):
    K, N, M, P, Q = map(int, input().split())
    
    asteroids = [tuple(map(int, input().split())) for _ in range(K)]
    
    x0, y0 = asteroids[0]
    
    invQ = mod_number(Q, N)
    invP = mod_number(P, M)
    
    best_t = 10**18
    answer = 0

    for i in range(K):
        x, y = asteroids[i]
        
        dx = (x - x0) % N
        dy = (y - y0) % M
        
        t1 = (dx * invQ) % N
        t2 = (dy * invP) % M
        
        if t1 == t2:
            if i != 0 and t1 < best_t:
                best_t = t1
                answer = i
    
    print(answer)
