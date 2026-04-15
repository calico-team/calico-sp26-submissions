import sys


def main():
    data = sys.stdin.read().split()
    it = iter(data)
    T = int(next(it))
    out = []
    for _ in range(T):
        A = next(it)
        B = next(it)
        j = 0
        chars = []
        for c in A:
            if j < len(B) and c == B[j]:
                chars.append(c)
                j += 1
            else:
                chars.append("#")
        out.append("".join(chars))
    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
