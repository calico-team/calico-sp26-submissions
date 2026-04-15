import sys
from fractions import Fraction
from functools import lru_cache

mp = {
    '<': (0, -1),
    '>': (0, 1),
    '^': (-1, 0),
    'v': (1, 0),
}

def solve():
    it = iter(sys.stdin.buffer.read().split())
    t = int(next(it))
    out = []

    for _ in range(t):
        n = int(next(it))
        m = int(next(it))
        g = [next(it).decode() for _ in range(n)]

        @lru_cache(None)
        def f(i, j):
            c = g[i][j]

            if c == 'X':
                return Fraction(0, 1)

            if c != 'S':
                x, y = mp[c]
                ni = i + x
                nj = j + y
                if ni < 0 or ni >= n or nj < 0 or nj >= m:
                    return Fraction(1, 1)
                return f(ni, nj)

            s = Fraction(0, 1)
            k = 0

            for x, y in mp.values():
                ni = i + x
                nj = j + y
                if ni < 0 or ni >= n or nj < 0 or nj >= m:
                    continue

                c2 = g[ni][nj]
                if c2 == 'X':
                    k += 1
                elif c2 in mp:
                    a, b = mp[c2]
                    if ni + a == i and nj + b == j:
                        continue
                    s += f(ni, nj)
                    k += 1

            return s / k if k else Fraction(0, 1)

        r = f(0, 0)
        out.append(f"{r.numerator} {r.denominator}")

    sys.stdout.write("\n".join(out))

def destroy_the_tiles(*a):
    return None

def read_your_input():
    return sys.stdin.buffer.read()

if __name__ == "__main__":
    solve()
