numCases = int(input())

for _ in range(numCases):
    lenCar, widCar, reqElec, elecPerStep = map(int, input().split())
    
    ansLaps = reqElec // (2 * (lenCar + widCar) * elecPerStep)
    print(ansLaps)