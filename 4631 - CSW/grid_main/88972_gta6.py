a=int(input())
for k in range(a):
    m=[int(i) for i in input().split()]
    for i in range(m[0]):
        n= []
        m1=[int(i) for i in input().split()]
        n.append(m1)
    x=n[0][0]
    y=n[0][1]
    while True:
        y+=m[3]
        x+=m[4]
        for i in n:
            if i[0]==x%m[1] and i[1]==y%m[2]:
                print(n.index(i))
                break