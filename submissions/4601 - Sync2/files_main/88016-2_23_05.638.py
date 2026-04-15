import sys

def censor_this_please(a, b):
    i = 0
    j = 0
    out = []

    # just go through A and try to build B
    while i < len(a):
        if j < len(b) and a[i] == b[j]:
            out.append(a[i])
            j += 1
        else:
            out.append('#')
        i += 1

    return "".join(out)


def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    idx = 1

    for _ in range(t):
        A = data[idx]
        B = data[idx + 1]
        idx += 2

        ans = censor_this_please(A, B)
        print(ans)


def read_your_input():
    return sys.stdin.read()


if __name__ == "__main__":
    main()