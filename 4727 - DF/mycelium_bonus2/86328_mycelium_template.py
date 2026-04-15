import sys

def floor_sum(n: int, m: int, a: int, b: int) -> int:
    ans = 0
    while True:
        if a >= m:
            ans += (n - 1) * n * (a // m) // 2
            a %= m
        if b >= m:
            ans += n * (b // m)
            b %= m
        y_max = a * n + b
        if y_max < m:
            return ans
        n = y_max // m
        b = y_max % m
        a, m = m, a

def comb2(n: int) -> int:
    return n * (n - 1) // 2 if n >= 2 else 0

def count_box_triangle(a: int, b: int, t: int) -> int:
    if a <= 0 or b <= 0 or t < 2:
        return 0
    h = t - 2
    return (
        comb2(h + 2)
        - comb2(h - a + 2)
        - comb2(h - b + 2)
        + comb2(h - a - b + 2)
    )

def sum_region_linear(L: int, upper: int) -> int:
    k = min(upper, (L - 1) // 9)
    if k <= 0:
        return 0
    B = L + 4 - 9 * k
    return floor_sum(k, 5, 9, B)

def sum_region_upper(a: int, b: int) -> int:
    g = 2 * a - 7 * b
    if g <= 0:
        return 0
    k = min(a, (g - 1) // 9)
    if k <= 0:
        return 0
    B = g - 1 - 9 * k
    return floor_sum(k, 5, 9, B)

def solve(xg: int, yg: int, xm: int, ym: int) -> int:
    dx = abs(xm - xg)
    dy = abs(ym - yg)
    a = max(dx, dy)
    b = min(dx, dy)
    D = a + b
    c = (2 * D + 4) // 5
    ans = c * (c + 1) // 2
    ans += sum_region_linear(2 * D, b)
    cc = (2 * a - 7 * b + 4) // 5
    if cc >= 1:
        ans += (cc - 1) * cc // 2
    ans += sum_region_linear(2 * D, a)
    t = (2 * D + 8) // 9
    ans += count_box_triangle(a, b, t - 1)
    ans += sum_region_upper(a, b)
    return ans

def main() -> None:
    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    t = int(next(it))
    out = []
    for _ in range(t):
        xg = int(next(it))
        yg = int(next(it))
        xm = int(next(it))
        ym = int(next(it))
        out.append(str(solve(xg, yg, xm, ym)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()
