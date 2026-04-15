for _ in range(int(input())):
    N = int(input())
    S1 = [input() for i in range(N)]
    S2 = [input() for i in range(N)]
    maximum = 0
    minimum = 0
    for i in range(N):
        a1 = S1[i].count("#")
        a2 = S2[i].count("#")
        maximum += a1*a2
        minimum += max(a1, a2)
    print(" ".join(map(str, [maximum, minimum])))
