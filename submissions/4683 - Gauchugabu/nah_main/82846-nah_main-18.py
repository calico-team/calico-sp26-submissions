t = int(input())
for i in range(t):
    n, p, r, k = map(int, input().split())
    curses = map(int, input().split())

    lose = False
    for j, curse in enumerate(curses):
        p -= curse
        if j != 0 and j % k == 0:
            p += r
        if p < 0:
            lose = True
            break
    if lose:
        print("nah i'd lose")
    else:
        print("nah i'd win")
            
        