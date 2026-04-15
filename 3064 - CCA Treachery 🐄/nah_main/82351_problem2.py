T = int(input())


for _ in range(T):
    N, P, R, K = map(int,input().split())
    curses = list(map(int,input().split()))
    defeated = 0
    works = True
    for elem in curses:
        if defeated >= K:
            defeated -= K
            P += R
        if P >= elem:
            P -= elem
            defeated += 1
        else:
            works = False
            break
    if works:
        print("nah i'd win")
    else:
        print("nah i'd lose")