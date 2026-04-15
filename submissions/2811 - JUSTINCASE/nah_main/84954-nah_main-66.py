__ = int(input())
L = []
for _ in range(__):
    N, P, R, K = map(int, input().split())
    LL = list(map(int, input().split()))
    kK = 0
    alive = 1
    for i in range(N):
        P -= LL[i]
        if P < 0:
            alive=0
            break
        kK += 1
        if kK == K:
            P += R
            kK = 0

    L.append(alive)


for ans in L:
    if ans!=0:
        print("nah i’d win")
    else:
        print("nah i’d lose")
