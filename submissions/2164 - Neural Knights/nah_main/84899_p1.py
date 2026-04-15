def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    jojoStartPower = P
    
    for i in range(0,N):
        jojoStartPower -= E[i]
        if jojoStartPower < 0:
            return "nah i'd lose"
        if (i + 1) % K == 0:
            jojoStartPower += R
    return "nah i'd win"


def main() -> None:
    T = int(input())
        
    for _ in range(T):
        jojo = input().split()
        N, P, R, K = map(int, jojo)
        power = input().split()
        E = list(map(int, power))
        print(solve(N, P, R, K, E))

if __name__ == "__main__":
    main()