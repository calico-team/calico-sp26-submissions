def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.
    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    curr_power = P
    defeated = 0 
    for i in E:
        curr_power -= i
        if curr_power < 0:
            return "nah i'd lose"
        defeated +=1
        if defeated % K == 0:
            curr_power+= R

    return "nah i'd win"

def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))

if __name__ == "__main__":
    main()
