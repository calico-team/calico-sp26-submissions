import math
def reduce_fraction(num, den):
    if num == 0:
        return (0, 1)
    gcd_val = math.gcd(abs(num), abs(den))
    return (num // gcd_val, den // gcd_val)
def add_fractions(num1, den1, num2, den2):
    new_num = num1 * den2 + num2 * den1
    new_den = den1 * den2
    return reduce_fraction(new_num, new_den)
def main():
    import sys
    input = sys.stdin.read().splitlines()
    ptr = 0
    T = int(input[ptr])
    ptr += 1
    for _ in range(T):
        n, m = map(int, input[ptr].split())
        ptr += 1
        a = []
        for _ in range(n):
            a.append(input[ptr])
            ptr += 1

        b = [[0] * m for _ in range(n)]
        c = [[1] * m for _ in range(n)]
        b[0][0] = 1

        d = 0
        e = 1

        while True:
            f = False
            g = [row.copy() for row in b]
            h = [row.copy() for row in c]

            for i in range(n):
                for j in range(m):
                    if b[i][j] == 0:
                        continue
                    ch = a[i][j]
                    if ch == '.' or ch == 'X':
                        continue

                    p = b[i][j]
                    q = c[i][j]

                    g[i][j] = 0
                    h[i][j] = 1
                    f = True

                    if ch == '<':
                        ni, nj = i, j - 1
                        if ni < 0 or ni >= n or nj < 0 or nj >= m:
                            d, e = add_fractions(d, e, p, q)
                        elif a[ni][nj] != 'X':
                            g[ni][nj], h[ni][nj] = add_fractions(g[ni][nj], h[ni][nj], p, q)
                    elif ch == '>':
                        ni, nj = i, j + 1
                        if ni < 0 or ni >= n or nj < 0 or nj >= m:
                            d, e = add_fractions(d, e, p, q)
                        elif a[ni][nj] != 'X':
                            g[ni][nj], h[ni][nj] = add_fractions(g[ni][nj], h[ni][nj], p, q)
                    elif ch == '^':
                        ni, nj = i - 1, j
                        if ni < 0 or ni >= n or nj < 0 or nj >= m:
                            d, e = add_fractions(d, e, p, q)
                        elif a[ni][nj] != 'X':
                            g[ni][nj], h[ni][nj] = add_fractions(g[ni][nj], h[ni][nj], p, q)
                    elif ch == 'v':
                        ni, nj = i + 1, j
                        if ni < 0 or ni >= n or nj < 0 or nj >= m:
                            d, e = add_fractions(d, e, p, q)
                        elif a[ni][nj] != 'X':
                            g[ni][nj], h[ni][nj] = add_fractions(g[ni][nj], h[ni][nj], p, q)
                    elif ch == 'S':
                        cnt = 0
                        u = dw = l = r = False

                        if i > 0:
                            cc = a[i - 1][j]
                            if cc == 'X':
                                u = True
                                cnt += 1
                            elif cc != '.':
                                if cc != 'v':
                                    u = True
                                    cnt += 1
                        if i < n - 1:
                            cc = a[i + 1][j]
                            if cc == 'X':
                                dw = True
                                cnt += 1
                            elif cc != '.':
                                if cc != '^':
                                    dw = True
                                    cnt += 1
                        if j > 0:
                            cc = a[i][j - 1]
                            if cc == 'X':
                                l = True
                                cnt += 1
                            elif cc != '.':
                                if cc != '>':
                                    l = True
                                    cnt += 1
                        if j < m - 1:
                            cc = a[i][j + 1]
                            if cc == 'X':
                                r = True
                                cnt += 1
                            elif cc != '.':
                                if cc != '<':
                                    r = True
                                    cnt += 1

                        if cnt > 0:
                            sz, sm = reduce_fraction(p, q * cnt)
                            if u and a[i - 1][j] != 'X':
                                g[i - 1][j], h[i - 1][j] = add_fractions(g[i - 1][j], h[i - 1][j], sz, sm)
                            if dw and a[i + 1][j] != 'X':
                                g[i + 1][j], h[i + 1][j] = add_fractions(g[i + 1][j], h[i + 1][j], sz, sm)
                            if l and a[i][j - 1] != 'X':
                                g[i][j - 1], h[i][j - 1] = add_fractions(g[i][j - 1], h[i][j - 1], sz, sm)
                            if r and a[i][j + 1] != 'X':
                                g[i][j + 1], h[i][j + 1] = add_fractions(g[i][j + 1], h[i][j + 1], sz, sm)

            b = g
            c = h
            if not f:
                break

        print(d, e)
if __name__ == "__main__":
    main()