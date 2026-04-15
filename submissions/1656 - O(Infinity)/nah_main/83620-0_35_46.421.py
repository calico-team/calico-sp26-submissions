for _ in range(int(input())):
    N,P,R,K = map(int,input().split())
    curses = list(map(int,input().split()))
    win = True
    currD = 0
    i = 0
    while i < N:
        currCurse = curses[i]
        if P-currCurse<0:
            if currD>=K:
                P+=R
                currD = 0
                continue
            else:
                win = False
                break
        currD+=1
        P-=currCurse
        i+=1
    print("nah i'd win") if win and P>=0 else print("nah i'd lose")