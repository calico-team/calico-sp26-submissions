t = int(input())
def fight(n, p, r, k, eList):
    cnt = 0
    for i in range(n):
        cnt += 1
        p -= eList[i]

        #print(p, '  ', cnt, k)
        if p < 0:
            return "nah I'd lose"
        if cnt >= k:
            cnt = 0
            p += r
    return "nah I'd win"
for i in range(t):
    inputList = input().split()
    n, p, r, k = int(inputList[0]), int(inputList[1]), int(inputList[2]), int(inputList[3])
    eList = input().split()
    for i in range(n):
        eList[i] = int(eList[i])
    print(fight(n, p, r, k, eList))
    
