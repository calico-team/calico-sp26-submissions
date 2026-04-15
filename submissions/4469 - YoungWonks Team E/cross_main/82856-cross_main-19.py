import sys

def main():
    input = sys.stdin.read().split()
    idx = 0
    t = int(input[idx])
    idx += 1

    for tc in range(t):
        n = int(input[idx])
        idx += 1
        m = int(input[idx])
        idx += 1

        for r in range(n):
            row = []
            for c in range(m):
                row.append(str((r + 2 * c) % 5))
            print(' '.join(row))

main()

#yo i gotta say WHO is making these questions yo :sob:;sob::sob: