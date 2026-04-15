augggggggg = int(input())
l = []
for i in range(augggggggg):
    n,p,r,k = [int(i) for i in input().split()]
    e = [int(i) for i in input().split()]

    de = 0
    kkkkk=0
    win = True
    stickmother = 0
    for c in e:
        while p < c and stickmother > 0:
            p += r
            stickmother -= 1
        if p < c:
            win = False
        p -= c
        de += 1
        if de % k == 0:
            stickmother +=1

    l.append(win)
for i in l:
    if i: print("nah i'd win")
    else: print("nah i'd lose")