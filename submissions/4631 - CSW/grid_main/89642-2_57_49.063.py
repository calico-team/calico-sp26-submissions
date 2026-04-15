t=int(input())
for time in range(t):
    n=int(input())
    b=[]
    a=[int(i) for i in input().split()]
    b=a
    for i in range(1,n-1):
        b[i]=b[i+1]+b[i-1]+a[i]-max(b[i+1],b[i-1],a[i])-min(b[i+1],b[i-1],a[i])
    if len(b)==2:
        b[0]=int((b[0]+b[1])/2)
        b[1]=b[0]
    for j in b:
        if b.index(j)==len(b)-1:
            print(j)
        else:
            print(j,end=' ')
