def solve(number, power, regen, requirement, curses) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    # YOUR CODE HERE
    curses_to_next_regen=requirement
    for i in range(number):
        if curses[i]>power:
            return "nah i'd lose"
        else:
            curses_to_next_regen-=1
            power-=curses[i]
        if curses_to_next_regen==0:
            curses_to_next_regen=requirement
            power+=regen
    return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
