def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    
    count = 0  # number of curses defeated since last RCT availability
    can_use = False  # whether RCT is available

    for i in range(N):
        # Check if we should use RCT before fighting
        if P - E[i] < 0:
            if can_use:
                P += R
                can_use = False
                count = 0
            else:
                return "nah i'd lose"

        # Fight the curse
        P -= E[i]
        count += 1

        # Check if RCT becomes available
        if count == K:
            can_use = True

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
