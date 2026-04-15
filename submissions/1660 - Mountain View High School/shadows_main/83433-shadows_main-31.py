for _ in range(int(input())):
    N = int(input())
    S1 = [list(input()) for i in range(N)]
    S2 = [list(input()) for i in range(N)]
    maximum = 0
    minimum = 0
    for i in range(N):
        a1 = 0
        a2 = 0
        for j in range(N):
            if S1[i][j] == "#":
                a1 += 1
            if S2[i][j] == "#":
                a2 += 1
        maximum += a1*a2
        minimum += max(a1, a2)
    print(" ".join(map(str, [maximum, minimum])))
