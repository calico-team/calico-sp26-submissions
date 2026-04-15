def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    charges = 0  # number of times we can use RCT

    for i in range(N):
        # Gain RCT availability after every K defeats
        if i > 0 and i % K == 0:
            charges += 1

        # If we are about to lose, try using RCT
        if P < E[i]:
            if charges > 0:
                P += R
                charges -= 1
            else:
                return "nah i'd lose"

        # Fight curse
        P -= E[i]

    return "nah i'd win"



    return ""


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
