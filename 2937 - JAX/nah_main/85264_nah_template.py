def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    # YOUR CODE HERE
    defeated = 0
    rct = 0
    if P >= sum(E):
        return "nah i'd win"
    for curse in E:
        if rct == K:
            P = P + R
            rct = 0
        if P >= curse:
            P = P - curse
            defeated += 1
            rct += 1
        elif P < curse:
            return "nah i'd lose"
        if defeated == len(E):
            return "nah i'd win"
    return "nah i'd win"
             
        


def main():
    T = int(input())
    for a in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
