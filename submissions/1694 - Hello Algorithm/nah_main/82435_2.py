numCases = int(input())

for _ in range(numCases):
    numCurses, startPower, healAmt, healReq = map(int, input().split())
    curses = list(map(int, input().split()))
    
    winFlag = True
    for i in range(numCurses):
        startPower -= curses[i]
        
        if startPower < 0:
            winFlag = False
            break
            
        if (i + 1) % healReq == 0:
            startPower += healAmt
            
    if winFlag:
        print("nah i'd win")
    else:
        print("nah i'd lose")