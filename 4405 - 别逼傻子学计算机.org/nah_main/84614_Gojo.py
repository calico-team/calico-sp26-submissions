T = int(input())

for _ in range(T):
    N, P, R, K = map(int, input().split())
    lst = list(map(int, input().split()))
    count = 0
    win = True

    for i in range(N):
        P -= lst[i]
        if P < 0:
            win = False
            break
        else:
            count += 1
            if count >= K:
                P = P + R
                count = 0

    if win:
        print("nah i'd win")
    else:
        print("nah i'd lose")