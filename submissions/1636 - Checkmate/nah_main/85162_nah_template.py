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
    power = P
    cum_wins = 0
    if E[0] > P: return "nah i'd lose"
    else:
        for i in E:
            power -= i
            if power < 0: return "nah i'd lose"
            cum_wins += 1
            if cum_wins == K: 
                power += R
                cum_wins = 0
    return "nah i'd win"
                

def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
