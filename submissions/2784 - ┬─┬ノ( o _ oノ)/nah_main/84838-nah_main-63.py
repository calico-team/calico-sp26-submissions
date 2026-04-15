t = int(input())
for i in range(t):
    n,p,r,k = map(int, input().split())
    curses = list(map(int, input().split()))
    if sum(curses) <= p:
        print("nah i'd win")
    else:
        b = 0
        beat = True
        for c in curses:
            p = p - c
            if b >= k:
                p = p + r
            if p < 0:
                print("nah i'd lose")
                beat = False
                break
            else:
                b = b + 1
        if b == n:
            print("nah i'd win")
        elif beat != False:
            print("nah i'd lose")

