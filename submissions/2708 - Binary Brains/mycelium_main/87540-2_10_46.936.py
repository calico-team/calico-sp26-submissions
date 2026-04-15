def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    span = abs(X_G - X_M) + abs(Y_G - Y_M) + 20
    l = min(X_G, X_M) - span
    r = max(X_G, X_M) + span
    b = min(Y_G, Y_M) - span
    t = max(Y_G, Y_M) + span

    g_tiles = {(X_G, Y_G)}
    s_tiles = {(X_M, Y_M)}
    busy = {
        (X_G, Y_G): 1,
        (X_M, Y_M): 2,
    }

    g_front = {(X_G, Y_G)}
    s_front = {(X_M, Y_M)}

    next_grass = 2
    next_shroom = 7
    current_tick = 0

    moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    while s_front:
        current_tick = min(next_grass, next_shroom)

        new_grass = set()
        if current_tick == next_grass:
            for px, py in g_front:
                for dx, dy in moves:
                    nx, ny = px + dx, py + dy
                    if not (l <= nx <= r and b <= ny <= t):
                        continue
                    if (nx, ny) not in busy:
                        new_grass.add((nx, ny))

        new_shroom = set()
        if current_tick == next_shroom:
            blocked_now = new_grass
            for px, py in s_front:
                for dx, dy in moves:
                    nx, ny = px + dx, py + dy
                    if not (l <= nx <= r and b <= ny <= t):
                        continue
                    if (nx, ny) in busy:
                        continue
                    if (nx, ny) in blocked_now:
                        continue
                    new_shroom.add((nx, ny))

        if new_grass:
            for cell in new_grass:
                busy[cell] = 1
            g_tiles |= new_grass
            g_front = new_grass
        elif current_tick == next_grass:
            g_front = set()

        if new_shroom:
            for cell in new_shroom:
                busy[cell] = 2
            s_tiles |= new_shroom
            s_front = new_shroom
        elif current_tick == next_shroom:
            s_front = set()

        if current_tick == next_grass:
            next_grass += 2
        if current_tick == next_shroom:
            next_shroom += 7

    return len(s_tiles)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
