for _ in range(int(input())):
    N,P,R,K = map(int,input().split())
    curses = list(map(int,input().split()))
    win = True
    currD = 0
    i = 0
    while i < N:
        currCurse = curses[i]
        if currD >= K:
            P += R
            currD = 0
            continue
        if P<currCurse:
            win = False
            break
        currD+=1
        P-=currCurse
        i+=1
    print("nah i'd win") if win else print("nah i'd lose")