def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    current_power = P
    count = 0

    for x in range(N):
        current_power -= E[x]
        if current_power < 0:
            return "nah i'd lose"
        count += 1
        if count % K == 0:
            current_power += R

    return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


def read_your_input():
    pass


if __name__ == "__main__":
    main()