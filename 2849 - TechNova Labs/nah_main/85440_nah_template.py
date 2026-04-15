import sys


def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    """
    Output whether Gojo will win the fight.

    N: Number of curses
    P: Gojo's starting power
    R: Amount of power Gojo can restore with Reverse Cursed Technique
    K: The cooldown of Reverse Cursed Technique
    E: List of power levels of curses
    """
    dylan_power = P
    used_rct = 0
    defeated = 0

    for curse_power in E:
        available_rct = defeated // K - used_rct
        while dylan_power < curse_power and available_rct > 0:
            dylan_power += R
            used_rct += 1
            available_rct -= 1

        if dylan_power < curse_power:
            return "nah i'd lose"

        dylan_power -= curse_power
        defeated += 1

    return "nah i'd win"


def main() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return

    it = iter(data)
    t = int(next(it))
    out = []

    for _ in range(t):
        n = int(next(it))
        p = int(next(it))
        r = int(next(it))
        k = int(next(it))
        e = [int(next(it)) for _ in range(n)]
        out.append(solve(n, p, r, k, e))

    sys.stdout.write("\n".join(out))


if __name__ == "__main__":
    main()


def read_your_input() -> list[tuple[int, int, int, int, list[int]]]:
    t = int(input())
    cases = []
    for _ in range(t):
        n, p, r, k = map(int, input().split())
        e = list(map(int, input().split()))
        cases.append((n, p, r, k, e))
    return cases
