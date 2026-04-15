t=int(input())
for a in range(t):
    n=int(input())
    l1=[input().strip() for i in range(n)]
    l2 = [input().strip() for i in range(n)]
    minV = 0
    maxV = 0
    for i in range(n):
        Co1=l1[i].count("#")
        Co2=l2[i].count("#")
        minV += max(Co1, Co2)
        maxV+=Co1*Co2
    print(maxV,minV)

