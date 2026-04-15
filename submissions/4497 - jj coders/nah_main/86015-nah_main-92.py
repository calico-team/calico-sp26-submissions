def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    last_heal = -10**9

    for i in range(N):

        # if power is not enough BEFORE fight, try healing first
        if P < E[i]:
            if i - last_heal > K:
                P += R
                last_heal = i
            else:
                return "nah i'd lose"

        # now fight
        P -= E[i]

        if P < 0:
            return "nah i'd lose"

    return "nah i'd win"