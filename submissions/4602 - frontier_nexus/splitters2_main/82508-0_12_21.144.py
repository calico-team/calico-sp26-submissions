t = int(input())
for _ in range(t):
    N, P, R, K = map(int, input().split())
    curses = list(map(int, input().split()))
    
    power = P
    defeated = 0
    lost = False

    for e in curses:
        power -= e
        if power < 0:
            lost = True
            break
        defeated += 1
        if defeated % K == 0:
            power += R

    if lost:
        print("nah i'd lose")
    else:
        print("nah i'd win")