for _ in range(int(input())):
    k,n,m,p,q=list(map(int,input().split()))
    c=[]
    for i in range(k):
        a=list(map(int,input().split()))
        c.append(a)
    x=c[0][0]
    y=c[0][1]
    while True:
        x=(x+q)%n
        y=(y+p)%m
        flag=False
        for i in range(k):
            if c[i][0]==x and c[i][1]==y:
                print(i)
                flag=True
                break
        if flag:
            break
