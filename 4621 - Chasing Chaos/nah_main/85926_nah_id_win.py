def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    # Simulate the fights in order
    for i in range(N):
        P -= E[i]
        
        # If power drops below 0 at any point, he loses
        if P < 0:
            return "nah i'd lose"
            
        # (i + 1) represents the number of curses defeated so far
        # If it's a multiple of K, heal by R
        if (i + 1) % K == 0:
            P += R
            
    # If the loop finishes, he survived them all
    return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()