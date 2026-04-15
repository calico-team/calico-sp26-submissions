
T = int(input())
for _ in range(T):
    N, P, R, K = map(int, input().split())
    E = list(map(int, input().split()))

    power = P
    heals = 0
    win = True

    for i in range(N):
        power -= E[i]

        if power < 0:
             if heals > 0:
                power += R
                heals -= 1
             else:
                  win = False
                  break

        if (i + 1) % K == 0:
            heals += 1
    print("nah i'd win" if win else "nah i'd lose")