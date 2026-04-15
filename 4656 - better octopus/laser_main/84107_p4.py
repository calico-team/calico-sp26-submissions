for _ in range(int(input())):
    a={}
    k,n,m,dy,dx=map(int,input().split())
    for i in range(k):
        ax,ay=map(int,input().split())
        if i==0:
            x,y=ax,ay
        a[(ax,ay)]=i
    while True:
        x=(x+dx)%n
        y=(y+dy)%m
        #print("debug:",x,y)
        if (x,y) in a:
            print(a[(x,y)])
            break
