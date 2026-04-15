import sys


def ints_from_stdin():
    data = sys.stdin.buffer.read()
    value = 0
    in_number = False

    for byte in data:
        if 48 <= byte <= 57:
            value = value * 10 + (byte - 48)
            in_number = True
        elif in_number:
            yield value
            value = 0
            in_number = False

    if in_number:
        yield value


def main():
    it = iter(ints_from_stdin())

    try:
        t = next(it)
    except StopIteration:
        return

    out = []

    for _ in range(t):
        n = next(it)
        m = next(it)

        for r in range(n):
            row = [str((r + 2 * c) % 5) for c in range(m)]
            out.append(" ".join(row))

    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
