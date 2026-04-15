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
    index=0
    fought=0
    if N==1:
        if P<E[0]:
            return "nah i'd lose"
    if P>sum(E):
        return "nah i'd win"
    else: 
        while index<N:
            P=P-E[index]
            fought=fought+1
            if len(E)-1==index:

                if P < E[index] and fought<K:
                    return "nad i'd lose"
                elif fought>=K:
                    P=P+R
                if P<=0:
                    return "nah i'd lose"
            else:
                if P < E[index+1] and fought<K:
                    return "nah i'd lose"
                elif fought>=K:
                    P=P+R
                if P<=0:
                    return "nah i'd lose"
            index=index+1
        if P>0:
            return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()