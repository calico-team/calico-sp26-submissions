def winlose(n,p,r,k,curses):
    if p>=sum(curses):
        print("nah i'd win")
        return
    else:
        nk=k
        for i in curses:
            if p>=i:
                p-=i
                nk-=1
            else:
                if nk<=0:
                    p+=r
                    nk=k
                else:
                    print("nah i'd lose")
                    return
        if p>=0:
            print("nah i'd win")
            return
        else:
            print("nah i'd lose")
            return
tc=int(input())
for i in range(tc):
    n,p,r,k=list(map(int,input().split()))
    curses=list(map(int,input().split()))
    winlose(n,p,r,k,curses)