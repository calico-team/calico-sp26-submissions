x = eval(input())
tList = []
gList = []
rList = []
for i in range(x):
    txt = input().strip()
    tList.append(txt)
    goal = input().strip()
    gList.append(goal)
#print(tList, gList)
for i in range(x):
    result = ''
    test = list(gList[i])
    g = list(gList[1])
    #print(test, '\n', g)
    for a in range(len(test)):
        tst = test[a]
        cnt = 0
        #print(a)
        if tst == g[cnt]:
            print(tst)
            result += tst
            cnt += 1
        else:
            result += '#'
    rList.append(result)
for i in range(len(rList)):
    print(rList[i])
