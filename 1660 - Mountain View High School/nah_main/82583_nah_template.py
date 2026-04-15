def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    curses = sorted(E)
    cool = K
    curnt = 0
    while P >= 0:
        if curnt >= len(curses):
            return("nah i’d win")
            break
        if P - curses[curnt] < 0:
            break
        else:
            P -= curses[curnt]
        cool -= 1
        if cool == 0:
            cool = K
            P += R
        curnt += 1
    return "nah i’d lose"


T = int(input())
for _ in range(T):
    x = list(map(int, input().split()))
    #print(x)
    N = x[0]
    P = x[1]
    R = x[2]
    K = x[3]
    E = list(map(int, input().split()))
    print(solve(N, P, R, K, E))
