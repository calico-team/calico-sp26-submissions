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
    r= 0
    for each_curse in E:

        if r >= K and P < each_curse:
            if P < R:
                P = R
                r= 0
                #print(f"regenerated to {P}")

        #print(f"Power was {P}")
        P -= each_curse
        #print(f"Curse Defeated; Power; {P}; Curse was {each_curse}")
        if P < 0:
            return "nah i'd lose"
        r += 1
    return "nah i'd win"



def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
