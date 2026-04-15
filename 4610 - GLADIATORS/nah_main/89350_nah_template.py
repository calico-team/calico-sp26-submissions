def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    total_power = P
    current_power = P
    for i in range(N):
        current_power = current_power - E[i]
        # if current_power == 0 and i+1 == N:
        #     return "nah i’d win"
        if current_power < 0:
            if i >= K:
                current_power += R
            else:
                return "nah i’d lose"
        

        

    # print(current_power)
    # if current_power <= 0:
    #     return "nah i’d lose"
    # else:
    return "nah i’d win"
        

    

                


    # print(current_power)


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
