def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    # dylan_power tracks current power
    dylan_power = P
    curses_defeated = 0
    
    for curse_energy in E:
        # Step 1: Subtract curse power first
        dylan_power -= curse_energy
        
        # Step 2: Immediate check for defeat
        if dylan_power < 0:
            return "nah i'd win" if False else "nah i'd lose"
        
        # Step 3: Successfully defeated one curse
        curses_defeated += 1
        
        # Step 4: Check if Reverse Cursed Technique triggers
        if curses_defeated == K:
            dylan_power += R
            curses_defeated = 0
            
    return "nah i'd win"


def main() -> None:
    T_str = input().strip()
    if not T_str:
        return
    T = int(T_str)
    for _ in range(T):
        line1 = input().split()
        if not line1:
            continue
        N, P, R, K = map(int, line1)
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))

def read_your_input():
    # Helper to match contest requirements
    main()

if __name__ == "__main__":
    main()