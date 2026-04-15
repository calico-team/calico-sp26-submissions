def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    curses = E
    count_for_reverse = 0
    main_count = 0
    while main_count<N:
        curse_power = curses[main_count]
        P-=curse_power
        # print(curse_power,"rem pwr")
        # print(count_for_reverse,"r count")
        main_count+=1
        count_for_reverse+=1
        # print(count_for_reverse,"r count")
        if P<0:
            return "nah i’d lose"
        if count_for_reverse == K:
            P+=R
            count_for_reverse=0
        # if P<0:
        #     return "nah i’d lose"
            
    return "nah i’d win"




def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
