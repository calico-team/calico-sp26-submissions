i=int(input())
L=[]
for _ in range(i):
    l,w,e,r=map(int,input().split())
    a=e/(2*(l+w)*r)
    L.append(a)
for ans in L:
    print(int(ans))
