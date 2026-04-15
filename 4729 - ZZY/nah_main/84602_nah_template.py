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
    flag=True
    if N==1:
        if P>E[0]:
            P-=E[0]
            flag=True
        elif P<=E[0]:
            flag=False
        if K<=0 and flag:
            P=P+R
    else:
        for i in range(N-1):
            if i+1>=K and flag:
                P=P+R
            if P>E[i]:
                P-=E[i]
                flag=True
            elif P<=E[i]:
                flag=False
                break

    if flag:
        print("nah i’d win")
    else:
        print("nah i’d lose")
    return ""


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
