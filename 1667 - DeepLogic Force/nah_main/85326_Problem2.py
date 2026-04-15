import sys
input = sys.stdin.readline

def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """

    dylan_power = P
    curses_defeated = 0

    for i in range(N):
        dylan_power -= E[i]

        if dylan_power < 0:
            return "nah i'd lose"

        curses_defeated += 1

        # use reverse cursed technique every K curses
        if curses_defeated % K == 0:
            dylan_power += R

    return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()


def read_your_input():
    main()