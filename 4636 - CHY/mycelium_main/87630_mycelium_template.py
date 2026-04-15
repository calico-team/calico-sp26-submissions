def solve(x_g: int, y_g: int, x_m: int, y_m: int) -> int:
    create_voronoi_7 = []
    q = [(x_m, y_m, 0)]
    v = {(x_m, y_m)}
    c, i = 0, 0
    while i < len(q):
        cx, cy, d = q[i]
        i += 1
        if 7 * d < 2 * (abs(cx - x_g) + abs(cy - y_g)) or d == 0:
            c += 1
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                n = (cx + dx, cy + dy)
                if n not in v:
                    v.add(n)
                    q.append((n[0], n[1], d + 1))
    return c
def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))
if __name__ == '__main__':
    main()
