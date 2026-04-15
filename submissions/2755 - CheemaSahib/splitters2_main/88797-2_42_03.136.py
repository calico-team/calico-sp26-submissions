import sys

def build(p, a, b):
    if a == 0 and b == 0:
        return 1, 1, [">"]

    q = p
    d = pow(2, a) * pow(3, b)
    op = []

    for _ in range(a):
        d //= 2
        c, q = divmod(q, d)
        op.append((2, c, q > 0))

    for _ in range(b):
        d //= 3
        c, q = divmod(q, d)
        op.append((3, c, q > 0))

    k = len(op)
    m = 2 * k + 1
    g = [['.'] * m for _ in range(3)]

    g[0][0] = 'v'
    g[1][0] = '>'

    for i, (t, c, ok) in enumerate(op):
        x = 2 * i + 1
        g[1][x] = 'S'

        if t == 2:
            if ok:
                g[0][x] = '^' if c else 'X'
                g[1][x + 1] = '>'
            else:
                g[0][x] = '^' if c >= 1 else 'X'
                g[1][x + 1] = '>' if c >= 2 else 'X'
        else:
            if ok:
                g[0][x] = '^' if c >= 1 else 'X'
                g[2][x] = 'v' if c >= 2 else 'X'
                g[1][x + 1] = '>'
            else:
                g[0][x] = '^' if c >= 1 else 'X'
                g[2][x] = 'v' if c >= 2 else 'X'
                g[1][x + 1] = '>' if c >= 3 else 'X'

    return 3, m, [''.join(r) for r in g]

def main():
    s = sys.stdin.buffer.read().splitlines()
    t = int(s[0])
    out = []
    j = 1

    for _ in range(t):
        cur = s[j].decode().strip()
        j += 1
        a = cur.split()
        if len(a) == 3:
            p, x, y = map(int, a)
        else:
            p, x, y = map(int, list(cur))
        n, m, g = build(p, x, y)
        out.append(f"{n} {m}")
        out.extend(g)

    sys.stdout.write("\n".join(out))

def destroy_the_tiles():
    return

def read_your_input():
    return sys.stdin.buffer.readline()

if __name__ == "__main__":
    main()
