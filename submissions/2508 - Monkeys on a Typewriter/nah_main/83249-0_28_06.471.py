def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    cur = P
    defeat = 0
    for i in range(N):
        cur -= E[i]
        defeat += 1
        if cur < 0:
            return "nah i'd lose"
        if cur == 0:
            if defeat >= K:
                if cur+R > 0:
                    cur += R
                    continue
                else:
                    return "nah i'd lose"
            else:
                return "nah i'd lose"
        if defeat >= K and P-cur >= R:
            cur += R
            defeat = 0
        if defeat >= K and P-cur < R:
            loss = R-(P-cur)
            if loss < R/K:
                cur += R
                defeat = 0
    return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
