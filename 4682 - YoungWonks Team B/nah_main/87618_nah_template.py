def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    kill_ct=0
    lost=False
    for i in E:
        P-=i
        kill_ct+=1
        if kill_ct%K==0:
            P+=R
            kill_ct=0
        if P<0:
            lost=True
            break
    if lost:
        return "nah i'd lose"
    else:
        return "nah i'd win"
    # YOUR CODE HERE


def main() -> None:
    print('hi')
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
