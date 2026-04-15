import sys


def solve(L, W, E, R):
    """
    Return the number of laps needed to charge the car (rounded up)

    L: Length of car
    W: Width of car
    E: Amount of electricity to generate
    R: Electricity generated per unit distance
    """

    perimeter = 2 * (L + W)
    energy_per_lap = perimeter * R
    laps_needed = (E + energy_per_lap - 1) // energy_per_lap

    return laps_needed


def read_your_input():
    data = [int(tok) for tok in sys.stdin.buffer.read().split() if tok.lstrip(b"-").isdigit()]
    if not data:
        return []

    it = iter(data)
    t = int(next(it))
    cases = []
    for _ in range(t):
        l = int(next(it))
        w = int(next(it))
        e = int(next(it))
        r = int(next(it))
        cases.append((l, w, e, r))
    return cases

def main():
    cases = read_your_input()
    out = []
    for l, w, e, r in cases:
        out.append(str(solve(l, w, e, r)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()