a=int(input())
for i in range(a):
    n=int(input())
    s1=[input().strip() for j in range(n)]
    s2 = [input().strip() for j in range(n)]
    value=0
    maxValue=0
    minValue=0
    l1=[0]*n
    l2=[0]*n
    for k in range(n):
        for m in range(n):
            if s1[k][m]=="#":
                l1[m]+=1
    for k in range(n):
        for m in range(n):
            if s2[k][m]=="#":
                l2[k]+=1
    for k in range(n):
        maxValue+=l1[k]*l2[k]
        minValue+=max(l1[k],l2[k])
    print(maxValue,minValue)