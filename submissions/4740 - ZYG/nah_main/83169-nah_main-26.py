
T = int(input())
for _ in range(T):
    N, P, R, K = map(int, input().split())
    E = list(map(int, input().split()))
        
    power = P
    win = True
        
    for i in range(N):
        if power < E[i]:
            win = False
            break
        power -= E[i]
            # 每打完K个恢复一次（不是最后一轮）
        if (i + 1) % K == 0 and i + 1 != N:
            power += R
        
    print("nah i'd win" if win else "nah i'd lose")
