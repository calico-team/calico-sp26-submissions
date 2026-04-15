T = int(input())
for test in range (0, T):
    N, P, R, K = map(int, input().split())
    E = list(map(int, input().split()))
    gojo_power = P
    curses = 0
    defeated_curses = 0
    win = True

    for i in range (0, N):
        gojo_power -= E[i]
        if gojo_power < 0: # gojo lost
            win = False
            break
        defeated_curses +=1 
        if defeated_curses % K == 0: # gojo uses rct
            gojo_power += R
        
    print("nah i'd win" if win else "nah i'd lose")