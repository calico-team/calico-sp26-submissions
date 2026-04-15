import sys
input = sys.stdin.readline

def solve(xg, yg, xm, ym):

    D = abs(xm - xg) + abs(ym - yg)
    max_radius = 2 * D // 9 + 2  # a little buffer just in case

    count = 0
    for dx in range(-max_radius, max_radius + 1):
        for dy in range(-(max_radius - abs(dx)), max_radius - abs(dx) + 1):
            dm = abs(dx) + abs(dy)
            dg = abs(dx + xm - xg) + abs(dy + ym - yg)
            if 7 * dm < 2 * dg:
                count += 1

    return count

def main():
    T = int(input())
    for _ in range(T):
        xg, yg, xm, ym = map(int, input().split())
        print(solve(xg, yg, xm, ym))

main()