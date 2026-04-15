def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    grass = {(X_G, Y_G)}
    mycelium = {(X_M, Y_M)}
    ever_mycelium = {(X_M, Y_M)}

    dirs = [(0,1),(0,-1),(1,0),(-1,0)]

    no_growth_streak = 0

    for tick in range(1, 100001):
        new_grass = set()
        new_mycelium = set()

        if tick % 2 == 0:
            for (x, y) in grass:
                for dx, dy in dirs:
                    nx, ny = x+dx, y+dy
                    if (nx, ny) not in grass and (nx, ny) not in mycelium:
                        new_grass.add((nx, ny))

        if tick % 7 == 0:
            for (x, y) in mycelium:
                for dx, dy in dirs:
                    nx, ny = x+dx, y+dy
                    if (nx, ny) not in grass and (nx, ny) not in mycelium:
                        new_mycelium.add((nx, ny))

        contested = new_grass & new_mycelium
        new_mycelium -= contested

        grass |= new_grass
        mycelium |= new_mycelium
        ever_mycelium |= new_mycelium

        if not new_mycelium:
            no_growth_streak += 1
        else:
            no_growth_streak = 0

        if no_growth_streak >= 14:
            break

    return len(ever_mycelium)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()