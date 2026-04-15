#1

a=int(input())
for k in range(a):
    m=[int(i) for i in input().split()]
    n=(m[0]+m[1])*2*m[3]
    print(m[2]//n)
