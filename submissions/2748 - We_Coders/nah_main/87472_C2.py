import sys


def solve() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(data)
    t = int(next(it))
    results = []

    for _ in range(t):
        num_curses = int(next(it))
        current_power = int(next(it))
        restore_amount = int(next(it))
        required_defeats = int(next(it))

        curse_powers = [int(next(it)) for _ in range(num_curses)]

        defeat_count = 0
        can_win = True

        for curse in curse_powers:
            if current_power < curse:
                can_win = False
                break

            current_power -= curse
            defeat_count += 1

            if defeat_count == required_defeats:
                current_power += restore_amount
                defeat_count = 0

        results.append("nah i’d win" if can_win else "nah i’d lose")

    sys.stdout.write("\n".join(results))


if __name__ == "__main__":
    solve()