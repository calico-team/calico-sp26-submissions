   
t=int(input())
for i in range(t):
    a=input().split()
    numcurses=int(a[0])
    power=int(a[1])
    reverse=int(a[2])
    numreverse=int(a[3])
    curses=input().split()
    count=0
    possible=True
    for j in range(numcurses):
        damage=int(curses[j])
        power-=damage
        if power<0:
            possible=False
            break
        count+=1
        if count%numreverse==0:
            power+=reverse
    if possible:
        print("nah i'd win")
    else:
        print("nah i'd lose")
