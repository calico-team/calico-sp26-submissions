def solve(x_g: int, y_g: int, x_m: int, y_m: int) -> int:
    create_voronoi_7 = []
    size = 100
    offset = 50
    f = [[0 for _ in range(size)] for _ in range(size)]
    gx, gy = x_g - x_m + offset, y_g - y_m + offset
    mx, my = offset, offset
    if 0 <= gx < size and 0 <= gy < size:
        f[gy][gx] = 1
    f[my][mx] = -1
    for t in range(1, 401):
        if t % 2 == 0:
            to_add = []
            for y in range(size):
                for x in range(size):
                    if f[y][x] == 1:
                        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                            nx, ny = x + dx, y + dy
                            if 0 <= nx < size and 0 <= ny < size:
                                if f[ny][nx] == 0:
                                    to_add.append((nx, ny))
            for nx, ny in to_add:
                f[ny][nx] = 1
        if t % 7 == 0:
            to_add = []
            for y in range(size):
                for x in range(size):
                    if f[y][x] == -1:
                        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                            nx, ny = x + dx, y + dy
                            if 0 <= nx < size and 0 <= ny < size:
                                if f[ny][nx] == 0:
                                    to_add.append((nx, ny))
            for nx, ny in to_add:
                if f[ny][nx] != 1:
                    f[ny][nx] = -1
    m = 0
    for row in f:
        for cell in row:
            if cell == -1:
                m += 1
    return m
def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))
if __name__ == '__main__':
    main()
