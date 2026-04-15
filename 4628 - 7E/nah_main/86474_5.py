dylan_power = 0

t = int(input())
for _ in range(t):
    N, P, R, K = map(int, input().split())
    E = list(map(int, input().split()))

    cnt = 0
    can_use = 0
    alive = True

    for i in range(N):
        P -= E[i]

        # ❗先判断（不能用刚获得的技能）
        if P < 0:
            need = (-P + R - 1) // R
            if need <= can_use:
                P += need * R
                can_use -= need
            else:
                alive = False
                break

        # ✅ 再更新击败数
        cnt += 1
        if cnt == K:
            can_use += 1
            cnt = 0

    print("nah i'd win" if alive else "nah i'd lose")