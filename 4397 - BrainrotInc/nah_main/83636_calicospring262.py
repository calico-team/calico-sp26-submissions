for test in range(int(input())):
    a=input().split()
    b=input().split()
    c=int(a[1])
    d=0
    e=True
    for i in range(int(a[0])):
        c-=int(b[i])
        if c>=0:
            d+=1
            if d==int(a[3]):
                c+=int(a[2])
                d=0
        else:
            e=False
            break
    if e:
        print("nah i’d win")
    else:
        print("nah i’d lose")
