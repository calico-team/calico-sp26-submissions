import time

def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses: 4
    P: Gojo's starting power: 5
    R: Amount of power Gojo can restore with Reverse Cursed Technique: 10
    K: The cooldown of Reverse Cursed Technique: 1
    E: List of power levels of curses
    """
    
    cooldown = 0

    for i in range(N):
        if cooldown == K:
            P += R
            cooldown = 0
        if E[i] > P:
            return "nah i'd lose"
        else:
            P -= E[i]
            cooldown += 1

    return "nah i'd win"




def main() -> None:
    T = int(input())
    # time.sleep(1)
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
