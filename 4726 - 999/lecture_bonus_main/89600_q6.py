t = int(input())

for i in range(t):
    xg, yg, xm, ym = map(int, input().split())

    d = abs(xg - xm) + abs(yg - ym)


    r = d + 8

    grass = {(xg, yg)}
    myc = {(xm, ym)}
    all_used = {(xg, yg), (xm, ym)}

    grass_front = {(xg, yg)}
    myc_front = {(xm, ym)}

    g_tick = 2
    m_tick = 7
    create_voronoi_7 = 0

    while myc_front:
        if g_tick < m_tick:
            new_grass = set()

            for x, y in grass_front:
                nx = x + 1
                ny = y
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in all_used:
                    new_grass.add((nx, ny))

                nx = x - 1
                ny = y
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in all_used:
                    new_grass.add((nx, ny))

                nx = x
                ny = y + 1
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in all_used:
                    new_grass.add((nx, ny))

                nx = x
                ny = y - 1
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in all_used:
                    new_grass.add((nx, ny))

            grass_front = new_grass
            grass |= new_grass
            all_used |= new_grass
            g_tick += 2

        elif m_tick < g_tick:
            new_myc = set()

            for x, y in myc_front:
                nx = x + 1
                ny = y
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in all_used:
                    new_myc.add((nx, ny))

                nx = x - 1
                ny = y
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in all_used:
                    new_myc.add((nx, ny))

                nx = x
                ny = y + 1
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in all_used:
                    new_myc.add((nx, ny))

                nx = x
                ny = y - 1
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in all_used:
                    new_myc.add((nx, ny))

            myc_front = new_myc
            myc |= new_myc
            all_used |= new_myc
            m_tick += 7

        else:
            new_grass = set()
            new_myc = set()

            for x, y in grass_front:
                nx = x + 1
                ny = y
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in all_used:
                    new_grass.add((nx, ny))

                nx = x - 1
                ny = y
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in all_used:
                    new_grass.add((nx, ny))

                nx = x
                ny = y + 1
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in all_used:
                    new_grass.add((nx, ny))

                nx = x
                ny = y - 1
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in all_used:
                    new_grass.add((nx, ny))

            used_after_grass = all_used | new_grass

            for x, y in myc_front:
                nx = x + 1
                ny = y
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in used_after_grass:
                    new_myc.add((nx, ny))

                nx = x - 1
                ny = y
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in used_after_grass:
                    new_myc.add((nx, ny))

                nx = x
                ny = y + 1
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in used_after_grass:
                    new_myc.add((nx, ny))

                nx = x
                ny = y - 1
                if abs(nx - xm) + abs(ny - ym) <= r and (nx, ny) not in used_after_grass:
                    new_myc.add((nx, ny))

            grass_front = new_grass
            myc_front = new_myc

            grass |= new_grass
            myc |= new_myc
            all_used |= new_grass
            all_used |= new_myc

            g_tick += 2
            m_tick += 7

    print(len(myc))
