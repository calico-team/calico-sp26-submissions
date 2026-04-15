import heapq
def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    # YOUR CODE HERE
    X_M -= X_G
    Y_M -= Y_G

    d0 = abs(X_M) + abs(Y_M)
    B = 4 * d0 + 20

    min_x = min(0, X_M) - B
    max_x = max(0, X_M) + B
    min_y = min(0, Y_M) - B
    max_y = max(0, Y_M) + B

    W = max_x - min_x + 1
    H = max_y - min_y + 1

    INF = 10**30

    best_time = [[INF] * H for _ in range(W)]
    owner = [[-1] * H for _ in range(W)]

    def inside(value, output):
        return min_x <= value <= max_x and min_y <= output <= max_y

    def idx(value, output):
        return value - min_x, output - min_y

    pq = []

    gx, gy = 0, 0
    mx, my = X_M, Y_M

    igx, igy = idx(gx, gy)
    imx, imy = idx(mx, my)

    best_time[igx][igy] = 0
    owner[igx][igy] = 0
    heapq.heappush(pq, (0, 0, gx, gy))

    best_time[imx][imy] = 0
    owner[imx][imy] = 1
    heapq.heappush(pq, (0, 1, mx, my))

    dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    while pq:
        t, typ, value, output = heapq.heappop(pq)
        ix, iy = idx(value, output)

        if t != best_time[ix][iy] or typ != owner[ix][iy]:
            continue

        step = 2 if typ == 0 else 7

        for dx, dy in dirs:
            nx, ny = value + dx, output + dy
            if not inside(nx, ny):
                continue

            nix, niy = idx(nx, ny)
            nt = t + step

            if nt < best_time[nix][niy] or (nt == best_time[nix][niy] and typ < owner[nix][niy]):
                best_time[nix][niy] = nt
                owner[nix][niy] = typ
                heapq.heappush(pq, (nt, typ, nx, ny))

    ans = 0
    for pos in range(W):
        for col in range(H):
            if owner[pos][col] == 1:
                ans += 1
    return ans


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
