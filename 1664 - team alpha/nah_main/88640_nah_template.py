def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses

#------------------------------


    """

    Gojo_defeated=0  # for tracking 

    for i in E : 
        P=P-i

        if P < 0: 
            return 'nah i’d lose'
    
        Gojo_defeated= Gojo_defeated+1

    
        if Gojo_defeated % K ==0:  # will check either heal or not 
            P=P+R 
    
    return 'nah i’d win' 




def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
