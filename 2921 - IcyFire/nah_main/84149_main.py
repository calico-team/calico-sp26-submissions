T = int(input())
for i in range(T):
    n, p, r, k = map(int, input().split())
    curses = list(map(int, input().split()))
    win = True
    for i in range(len(curses)):
        p -= curses[i]
        if p < 0:
            win = False
            break
        if (i + 1) % k == 0:
            p += r
    if win:
        print("nah i'd win")
    else:
        print("nah i'd lose")