def solve(N, P, R, K, E):
    powerT = P
    curseD = 0
    for cursedP in E:
        powerT -= cursedP
        if powerT < 0:
            return "nah i'd lose"
        curseD += 1
        if curseD % K == 0:
            powerT += R
    return "nah i'd win"
def read():
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))
read()