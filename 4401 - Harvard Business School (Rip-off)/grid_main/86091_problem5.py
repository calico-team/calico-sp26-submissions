cases=int(input())

for a in range(cases):
    floors=int(input())
    topTower = list(map(int, input().split()))

    bestCost=100000000000000
    bestBottom=[]
    choices=topTower

    if floors==1:
        for b1 in choices:
            bottomTower=[b1]
            total=0
            for i in range(floors-1):
                total+=abs(topTower[i]-topTower[i+1])
            for i in range(floors-1):
                total+=abs(bottomTower[i]-bottomTower[i+1])
            for i in range(floors):
                total+=abs(topTower[i]-bottomTower[i])
            if total<bestCost:
                bestCost=total
                bestBottom=bottomTower

    elif floors==2:
        for b1 in choices:
            for b2 in choices:
                bottomTower=[b1,b2]
                total=0
                for i in range(floors-1):
                    total+=abs(topTower[i]-topTower[i+1])
                for i in range(floors-1):
                    total+=abs(bottomTower[i]-bottomTower[i+1])
                for i in range(floors):
                    total+=abs(topTower[i]-bottomTower[i])
                if total<bestCost:
                    bestCost=total
                    bestBottom=bottomTower

    elif floors==3:
        for b1 in choices:
            for b2 in choices:
                for b3 in choices:
                    bottomTower=[b1,b2, b3]
                    total=0
                    for i in range(floors-1):
                        total+=abs(topTower[i]-topTower[i+1])
                    for i in range(floors-1):
                        total+=abs(bottomTower[i]-bottomTower[i+1])
                    for i in range(floors):
                        total+=abs(topTower[i]-bottomTower[i])
                    if total<bestCost:
                        bestCost=total
                        bestBottom=bottomTower
    print(bestBottom)