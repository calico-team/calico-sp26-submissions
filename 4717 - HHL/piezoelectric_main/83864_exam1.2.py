import sys

def main():
    iterator = iter(sys.stdin)

    try:
        next(iterator)
    except StopIteration:
        return

    write = sys.stdout.write

    for line in iterator:
        parts = line.split()
        if not parts:
            continue

        L, W, E, R = map(int, parts)
        lap_energy = 2 * (L + W) * R

        if lap_energy > 0:
            ans = 0 if E <= 0 else (E + lap_energy - 1) // lap_energy
        else:
            ans = 0 if E <= 0 else -1

        write(f"{ans}\n")

if __name__ == '__main__':
    main()