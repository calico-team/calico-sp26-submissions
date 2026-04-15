T = int(input())
for _ in range(T):
    N = int(input())
    S1 = []
    for i in range(N):
        S1.append(input())
    S2 = []
    for i in range(N):
        S2.append(input())

    tmax = 0
    tmin = 0

    for r in range(N):
        a = 0
        for c in range(N):
            if S1[r][c] == '#':
                a += 1
        b = 0
        for h in range(N):
            if S2[r][h] == '#':
                b += 1

        tmax += a * b
        tmin += max(a, b)

    print(tmax, tmin)

# 8 4
# 17 7
# 16 8
# 16 8
# 21 10
# 0 0