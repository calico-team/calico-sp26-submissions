for _ in range(int(input())):
    a, p, r, c=map(int,input().split())
    curses=list(map(int,input().split()))
    count=0
    win=1
    for i in range(a):
        if curses[i]>p:
            print("nah i'd lose")
            win=0
            break
        p-=curses[i]
        count+=1
        if count==c:
            count=0
            p+=r
    if win:
        print("nah i'd win")
