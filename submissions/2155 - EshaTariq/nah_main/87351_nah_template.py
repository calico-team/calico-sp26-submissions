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
    current_power = P
    curses_defeated = 0
    
    for power_needed in E:
        current_power -= power_needed
        
        if current_power < 0:
            return "nah i'd lose"
            
        curses_defeated += 1
        
        # Check if Gojo can use Reverse Cursed Technique
        if curses_defeated % K == 0:
            current_power += R
            
    return "nah i'd win"
    return ""


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
