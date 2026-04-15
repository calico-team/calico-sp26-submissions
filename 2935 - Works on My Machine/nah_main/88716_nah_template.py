def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    power = P
    
    curses = 0

    lose = False
    
    for i in range(len(E)):
        power -= E[i]

        if power < 0:
            if curses >= K:
                power += R
                curses = 1
                continue
            else:
                lose = True
                break
        else:
            curses += 1
            continue

        
    
    if lose:
        return "nah i'd lose"
    else:
        return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
