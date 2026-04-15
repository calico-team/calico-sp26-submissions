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
            if p < 0:
                if b >= k:
                    p = p + r
                    if p < 0:
                        print("nah i'd loose")
                        beat = False
                        break
                    else:
                        b = b + 1
                else:
                    print("nah i'd loose")
                    beat = False
                    break
            else:
                b = b + 1
        if beat == True:
            print("nah i'd win")

