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
    length = []
    total_E = sum(E)
    if P > total_E:
        return "nah i'd win"
    elif P < total_E:
        for i in E:
            if P > i:
                P = P - i
                length.append(i)
                
                
            elif P < i:
                if len(length) >= K:
                        P = P + K
                        
                elif len(length) < K:
                        return "nah i'd lose"
            


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
