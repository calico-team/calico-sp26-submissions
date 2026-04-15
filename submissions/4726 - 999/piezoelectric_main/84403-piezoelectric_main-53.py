a=int(input())
for i in range(a):
    l1,l2,l3,l4=map(int,input().split())
    k=2*(l1+l2)*l4
    if l3%l4==0:
        print(l3//k)
    else:
        print(l3//k+1)