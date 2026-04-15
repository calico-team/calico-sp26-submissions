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
    total_power = sum(E)
    index = 0
    kills = 0
    
    if P >= total_power:
        return "nah i'd win"

    else:
        for i in range(N):
            if P >= E[index]:
                P -= E[index]
                index += 1
                kills += 1
            elif P < E[index]:
                if kills >= K:
                    kills = 0
                    P += R
                else:
                    return "nah i'd lose"
        return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
    