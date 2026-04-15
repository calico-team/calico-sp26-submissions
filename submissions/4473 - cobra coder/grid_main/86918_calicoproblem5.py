t=input()
t=int(t)
for i in range(t):
    n=input()
    n=int(n)
    a=input().split()
    b=[]
    for j in a:
        b.append(int(j))
    b.sort()
    m=b[n//2]
    c=[]
    for j in range(n):
        c.append(str(m))
    print(" ".join(c))
