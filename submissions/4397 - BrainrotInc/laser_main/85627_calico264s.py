for test in range(int(input())):
    a=input().split()
    b=input().split()
    c=[]
    for i in range(int(a[0])-1):
        c.append(input().split())
    f=int(b[0])
    g=int(b[1])
    d=True
    while d:
        f=(f+int(a[3]))%int(a[1])
        g=(g+int(a[4]))%int(a[2])
        for j in range(len(c)):
            if int(c[j][0])==f and int(c[j][1])==g:
                print(j+1)
                d=False
                break
        if not d:
            break
        if f==int(b[0]) and g==int(b[1]):
            print(0)
            d=False
