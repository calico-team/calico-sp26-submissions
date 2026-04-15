t=int(input())
for time in range(t):
    n=int(input())
    b=[]
    a=[int(i) for i in input().split()]
    b=a
    for i in range(1,n-1):
        if abs(b[i]-b[i+1])+abs(b[i]-b[i-1])+abs(a[i]-b[i])>abs(a[i]-b[i+1])+abs(b[i-1]-b[i+1])+abs(b[i+1]-b[i+1]):
            b[i]=b[i+1]
    for j in b:
        if b.index(j)==len(b)-1:
            print(j)
        else:
            print(j,end=' ')
