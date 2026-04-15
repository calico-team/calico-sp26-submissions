a=int(input())
for i in range(a):
    n=int(input())
    s1=[input().strip() for j in range(n)]
    s2 = [input().strip() for j in range(n)]
    maxValue = 0
    minValue=0
    for j in range(n):
        c1=s1[j].count("#")
        c2=s2[j].count("#")
        maxValue+=c1*c2
        minValue+=max(c1,c2)
    print(maxValue,minValue)