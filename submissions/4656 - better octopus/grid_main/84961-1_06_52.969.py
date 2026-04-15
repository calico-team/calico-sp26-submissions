for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if n==1:
        print(a[0])
    elif n==2:
        print(" ".join(a))
    elif n==3:
        x,y,z=a[0],a[1],a[2]
        if y>max(x,z):
            y=max(x,z)
        elif y<min(x,z):
            y=min(x,z)
        print(x,y,z)
