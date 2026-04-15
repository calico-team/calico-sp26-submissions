#1
'''
a=int(input())
for k in range(a):
    m=[int(i) for i in input().split()]
    n=(m[0]+m[1])*2*m[3]
    print(m[2]//n)
'''
#4
'''
a=int(input())
for k in range(a):
    m=[int(i) for i in input().split()]
    n=[]
    for i in range(m[0]):
        m1=[int(i) for i in input().split()]
        n.append(m1)
    x=n[0][0]
    y=n[0][1]
    flag=False
    while flag==False:
        y+=m[3]
        x+=m[4]
        for i in n:
            if i[0]==x%m[1] and i[1]==y%m[2]:
                flag=True
                print(n.index(i))
'''
#4b

a=int(input())  
for k in range(a):
    m=[int(i) for i in input().split()]
    n=[]
    b=[]
    for i in range(m[0]):
        m1=[int(i) for i in input().split()]
        n.append(m1)
    n.pop(0)
    for i in n:
        b.append(abs(i[0]-i[1]))
    print(b.index(min(b)))   
