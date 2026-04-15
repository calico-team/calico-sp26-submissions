import sys

def solve_case(n, a):
    if n == 1:
        return [a[0]]

    if n == 2:
        return [a[0], a[1]]


    candidates = {
        a[0], a[1], a[2],
        min(a[0], a[1]), max(a[0], a[1]),
        min(a[1], a[2]), max(a[1], a[2]),
        min(a[0], a[2]), max(a[0], a[2]),
    }

    best = None
    ans = None

    # best b3 is anywhere between a3 and x
    # so we can just pick clipped vals
    for x in candidates:
        b1 = x
        if b1 < min(a[0], x):
            b1 = min(a[0], x)
        if b1 > max(a[0], x):
            b1 = max(a[0], x)

        b3 = x
        if b3 < min(a[2], x):
            b3 = min(a[2], x)
        if b3 > max(a[2], x):
            b3 = max(a[2], x)

        cur = abs(b1 - x) + abs(x - b3) + abs(a[0] - b1) + abs(a[1] - x) + abs(a[2] - b3)

        if best is None or cur < best:
            best = cur
            ans = [b1, x, b3]

    return ans

def main():
    data = input().split()
    maps = int(data[0])
    ptr = 1
    out = []

    for _ in range(maps):
        n = int(data[ptr])
        ptr += 1
        a = list(map(int, data[ptr:ptr + n]))
        ptr += n
        b = solve_case(n, a)
        out.append(" ".join(map(str, b)))

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()