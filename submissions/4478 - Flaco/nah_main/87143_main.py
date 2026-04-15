import sys


def ints_from_stdin():
    data = sys.stdin.buffer.read()
    num = 0
    sign = 1
    in_num = False

    for b in data:
        if 48 <= b <= 57:
            num = num * 10 + (b - 48)
            in_num = True
        elif b == 45:
            sign = -1
        else:
            if in_num:
                yield sign * num
                num = 0
                sign = 1
                in_num = False

    if in_num:
        yield sign * num


def can_win(n, start_power, regen_power, cooldown_k, enemies):
    power = start_power
    charges = 0
    defeated = 0

    for enemy_power in enemies:
        if power < enemy_power and charges > 0:
            needed = (enemy_power - power + regen_power - 1) // regen_power
            if needed > charges:
                needed = charges
            power += needed * regen_power
            charges -= needed

        if power < enemy_power:
            return False

        power -= enemy_power
        defeated += 1

        if defeated % cooldown_k == 0:
            charges += 1

    return True


def main():
    it = iter(ints_from_stdin())

    try:
        t = next(it)
    except StopIteration:
        return

    out = []

    for _ in range(t):
        n = next(it)
        start_power = next(it)
        regen_power = next(it)
        cooldown_k = next(it)

        enemies = [next(it) for _ in range(n)]

        if can_win(n, start_power, regen_power, cooldown_k, enemies):
            out.append("nah i'd win")
        else:
            out.append("nah i'd lose")

    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
