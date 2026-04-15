a=int(input())
for i in range(a):
    n=int(input())
    s1=[input().strip() for j in range(n)]
    s2 = [input().strip() for j in range(n)]
    maxValue=0
    minValue=0
    for k in range(n):
        l1=s1[i].count("#")
        l2=s2[i].count("#")
        maxValue+=l1*l2
        minValue+=max(l1,l2)
    print(maxValue,minValue)