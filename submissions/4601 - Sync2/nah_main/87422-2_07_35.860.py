
T= int(input())

for _ in range(T):
    N, P, R, K = map(int, input().split())
    arr = list(map(int, input().split()))

    fight = 0
    alive = True

    for e in arr:
        if P < e:
            alive = False
            break

        P -= e
        fight += 1

        if fight == K:
            P += R
            fight = 0

    if alive:
        print("nah i’d win")
    else:
        print("nah i’d lose")