t = int(input())
for i in range(t):
    N,P,R,K = map(input().split())
    E = list(map(int, input().split()))
    cnt = 0
    can_use = 0
    alive = True
    for j in range(N):
        P -= E[j]
        cnt+=1
        if cnt == K:
            can_use +=1
            cnt = 0
        if P < 0:
            if can_use > 0:
                P += R
                can_use -= 1
            else:
                alive = False
                break
    print("nah I'd win" if alive else "nah i'd lose")