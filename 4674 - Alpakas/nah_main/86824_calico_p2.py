def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:"""
    Output whether Gojo will win the fight.
    """
    current_power = P
    defeated_count = 0

    for curse_power in E:
        # Subtract curse energy from Gojo's current power 
        current_power -= curse_power
        
        # If power level falls below 0, he is defeated 
        if current_power < 0:
            return "nah i'd lose"
        
        # Increment the count of defeated curses [cite: 14]
        defeated_count += 1
        
        # Use Reverse Cursed Technique every K curses [cite: 14]
        if defeated_count == K:
            current_power += R
            defeated_count = 0 # Reset counter for next K curses [cite: 14]

    # If all curses are defeated without power falling below 0 [cite: 16]
    return "nah i'd win"
    


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
