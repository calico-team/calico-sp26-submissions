import sys


def censor_to_subsequence(a, b):
    out = ["#"] * len(a)
    j = 0

    for i, ch in enumerate(a):
        if j < len(b) and ch == b[j]:
            out[i] = ch
            j += 1

    return "".join(out)


def main():
    lines = sys.stdin.buffer.read().splitlines()
    if not lines:
        return

    t = int(lines[0])
    idx = 1
    ans = []

    for _ in range(t):
        a = lines[idx].decode()
        b = lines[idx + 1].decode()
        idx += 2
        ans.append(censor_to_subsequence(a, b))

    sys.stdout.write("\n".join(ans) + "\n")


if __name__ == "__main__":
    main()
