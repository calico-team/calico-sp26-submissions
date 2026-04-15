def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    
    S = 0
    for i in range(0, N):
        S = E[i]
        if (P < S):
            return "nah i'd lose"
        P -= E[i]
        if (((i % K) == K - 1)):
            P += R
    
    # YOUR CODE HERE
    return "nah i'd win"

from itertools import islice 

def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
