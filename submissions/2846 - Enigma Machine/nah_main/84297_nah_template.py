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
    defeated_curses=0
    for index in range(N):
        if P>=E[index]:
            P-=E[index]
            defeated_curses+=1
        if P>0 and defeated_curses==K:
            P+=R
            defeated_curses=0
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
