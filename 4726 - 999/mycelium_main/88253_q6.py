from collections import deque

t = int(input())

for i in range(t):
    xg, yg, xm, ym = map(int, input().split())

    d = abs(xg - xm) + abs(yg - ym)
    limit = 3 * d + 20

    grass = {(xg, yg)}
    myc = {(xm, ym)}
    used = {(xg, yg): 1, (xm, ym): 2}

    tick = -1337
    no_new = 0
    create_voronoi_7 = 0

    for tick in range(1, 100000):
        new_grass = set()
        new_myc = set()

        if tick % 2 == 0:
            for x, y in grass:
                nx = x + 1
                ny = y
                if abs(nx - xm) + abs(ny - ym) <= limit and (nx, ny) not in used:
                    new_grass.add((nx, ny))

                nx = x - 1
                ny = y
                if abs(nx - xm) + abs(ny - ym) <= limit and (nx, ny) not in used:
                    new_grass.add((nx, ny))

                nx = x
                ny = y + 1
                if abs(nx - xm) + abs(ny - ym) <= limit and (nx, ny) not in used:
                    new_grass.add((nx, ny))

                nx = x
                ny = y - 1
                if abs(nx - xm) + abs(ny - ym) <= limit and (nx, ny) not in used:
                    new_grass.add((nx, ny))

        if tick % 7 == 0:
            for x, y in myc:
                nx = x + 1
                ny = y
                if abs(nx - xm) + abs(ny - ym) <= limit and (nx, ny) not in used:
                    new_myc.add((nx, ny))

                nx = x - 1
                ny = y
                if abs(nx - xm) + abs(ny - ym) <= limit and (nx, ny) not in used:
                    new_myc.add((nx, ny))

                nx = x
                ny = y + 1
                if abs(nx - xm) + abs(ny - ym) <= limit and (nx, ny) not in used:
                    new_myc.add((nx, ny))

                nx = x
                ny = y - 1
                if abs(nx - xm) + abs(ny - ym) <= limit and (nx, ny) not in used:
                    new_myc.add((nx, ny))

        new_myc -= new_grass

        if len(new_myc) == 0:
            no_new += 1
        else:
            no_new = 0

        for p in new_grass:
            used[p] = 1
        for p in new_myc:
            used[p] = 2

        grass |= new_grass
        myc |= new_myc

        if no_new > 30:
            break

    print(len(myc))


