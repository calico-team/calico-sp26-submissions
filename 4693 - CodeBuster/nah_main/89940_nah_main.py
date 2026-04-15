T = int(input())
    
for _ in range(T):
    N, P, R, K = map(int, input().split())
    E = list(map(int, input().split()))
    eliminated = 0
    alive = True
    for i in range(N):
        P = P - E[i]
        if P < 0:
            print("nah i'd lose")
            alive = False
            break
        eliminated = eliminated + 1
        if eliminated % K == 0:
            P = P + R
    if eliminated == N:
        print("nah i'd win")
