import sys


def main():
    tokens = sys.stdin.buffer.read().split()
    if not tokens:
        return

    pos = 0
    t = int(tokens[pos])
    pos += 1

    out = []

    for _ in range(t):
        n = int(tokens[pos])
        pos += 1

        s1_counts = [0] * n
        s2_counts = [0] * n

        for i in range(n):
            s1_counts[i] = tokens[pos].count(b"#")
            pos += 1

        for i in range(n):
            s2_counts[i] = tokens[pos].count(b"#")
            pos += 1

        max_volume = 0
        min_volume = 0

        for i in range(n):
            a = s1_counts[i]
            b = s2_counts[i]
            max_volume += a * b
            if a and b:
                min_volume += a if a >= b else b

        out.append(f"{max_volume} {min_volume}")

    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
