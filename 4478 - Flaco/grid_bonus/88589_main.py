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


def solve_case(a):
    n = len(a)

    left = [0] * n
    right = [0] * n

    left[0] = a[0]
    right[0] = a[0]

    for i in range(1, n):
        x = a[i]
        l = left[i - 1]
        r = right[i - 1]

        if x < l:
            left[i] = x
            right[i] = l
        elif x > r:
            left[i] = r
            right[i] = x
        else:
            left[i] = x
            right[i] = x

    b = [0] * n
    b[-1] = left[-1]

    for i in range(n - 2, -1, -1):
        z = b[i + 1]
        l = left[i]
        r = right[i]

        if z < l:
            b[i] = l
        elif z > r:
            b[i] = r
        else:
            b[i] = z

    return b


def main():
    it = iter(ints_from_stdin())

    try:
        t = next(it)
    except StopIteration:
        return

    out = []

    for _ in range(t):
        n = next(it)
        a = [next(it) for _ in range(n)]
        b = solve_case(a)
        out.append(" ".join(map(str, b)))

    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
