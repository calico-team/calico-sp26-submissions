import sys


def main():
    line = sys.stdin.readline().strip()
    if not line:
        return
    t = int(line)

    results = []

    for _ in range(t):
        L, W, E, R = map(int, sys.stdin.readline().split())
        lap_energy = 2 * (L + W) * R

        if lap_energy > 0:
            results.append(0 if E <= 0 else (E + lap_energy - 1) // lap_energy)
        else:
            results.append(0 if E <= 0 else -1)

    if results:
        print('\n'.join(map(str, results)))

if __name__ == '__main__':
    main()