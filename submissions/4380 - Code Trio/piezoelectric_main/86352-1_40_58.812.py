T = int(input())
for i in range(T):
    L,W,E,R = map(int, input().split())
    perimeter = 2*(L+W)
    EnergyPerLap = perimeter*R
    TotalLap = E//EnergyPerLap
    print(TotalLap)


