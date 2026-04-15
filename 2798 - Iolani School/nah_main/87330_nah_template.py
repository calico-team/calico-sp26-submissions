def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    gojoPower = P
    counter = N
    while (counter - 1) >= 0:
        if (counter - 1) % K != 0:
            gojoPower -= E[counter - 1]
            counter += -1
        else:
            gojoPower += R
            gojoPower -= E[counter - 1]
            counter += -1
    
    if gojoPower > 0:
        return "nah i'd win"
    else:
        return "nah i'd lose"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
