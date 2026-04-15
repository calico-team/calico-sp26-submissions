def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    last_use = -10**9  # last index where RCT was used

    for i in range(N):
        # if not enough power, try healing
        if P < E[i]:
            if i - last_use > K:
                P += R
                last_use = i
            else:
                return "nah i'd lose"

        # fight
        P -= E[i]

        if P < 0:
            return "nah i'd lose"

    return "nah i'd win"