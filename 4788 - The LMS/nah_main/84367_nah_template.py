def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: health
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    hp = P
    kills = 0
    heals = 0

    for dmg in E:
        if hp < dmg:
            if heals > 0:
                hp += R
                heals -= 1

            if hp < dmg:
                return "nah i'd lose"

            hp -= dmg
            kills += 1

            if K > 0 and kills % k == 0:
                heals += 1
    return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
