for test in range(int(input())):
    a=input()
    b=input()
    c=0
    d=""
    for i in a:
        if c<len(b)and i==b[c]:
            d+=i
            c+=1
        else:
            d+="#"
    print(d)
