t=input()
t=int(t)
for j in range(t):
    k,n,m,p,q=input().split()
    k=int(k)
    n=int(n)
    m=int(m)
    p=int(p)
    q=int(q)
    a=[]
    for i in range(k):
        x,y=input().split()
        a.append((int(x),int(y)))
    x=a[0][0]
    y=a[0][1]
    hit=0
    for v in range(n*m):
        x=(x+q)%n
        y=(y+p)%m
        for i in range(k):
            if a[i][0]==x and a[i][1]==y:
                print(i)
                hit=1
                break
        if hit==1:
                break
    if hit==0:
            print(0)
            
                
        
