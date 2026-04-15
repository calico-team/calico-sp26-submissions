d = [[1, 0], [0, 1], [-1, 0], [0, -1]]


def solve(mx, my):
    def expand(growths, offset, border):
        nb = set()
        ox, oy = offset
        for b in border:
            x, y = b[0] - offset[0], b[1] - offset[1]
            for dx, dy in d:
                nx, ny = dx + x, dy + y
                cx, cy = nx + ox, ny + oy
                if abs(nx) + abs(ny) <= growths or (cx, cy) in seen:
                    continue
                nb.add((cx, cy))
        return nb

    seen = set()
    t = 0
    dist = mx + my
    while ((t + 1) // 2) + ((t + 1) // 7) < dist:
        t += 1
    grass_border = set()
    g_growths = t // 2
    for i in range(0, t // 2):
        grass_border.add((g_growths - i, i))
        grass_border.add((-i, g_growths - i))
        # grass_border.add((-g_growths + i, -i))
        grass_border.add((i, -g_growths + i))
    if not grass_border:
        grass_border = {(0, 0)}

    mycelium_border = set()
    m_growths = t // 7
    for i in range(0, m_growths):
        mycelium_border.add((m_growths - i + mx, i + my))
        mycelium_border.add((-i + mx, m_growths - i + my))
        mycelium_border.add((-m_growths + i + mx, -i + my))
        mycelium_border.add((i + mx, -m_growths + i + my))
    if not mycelium_border:
        mycelium_border = {(mx, my)}
    seen |= grass_border
    seen |= mycelium_border

    mycelium_area = 2 * m_growths * (m_growths + 1) + 1

    pot_mycelium = expand(m_growths, (mx, my), mycelium_border)
    mycelium_adj = pot_mycelium & grass_border
    while mycelium_border:
        t += 1
        if t % 2 == 0:
            grass_border = expand(g_growths, (0, 0), grass_border)
            grass_border -= mycelium_border

            seen |= grass_border
            mycelium_adj |= grass_border & pot_mycelium
        if t % 7 == 0:
            mycelium_border = pot_mycelium
            mycelium_border -= mycelium_adj
            seen |= mycelium_border

            mycelium_area += len(mycelium_border)
            pot_mycelium = expand(m_growths, (mx, my), mycelium_border)

    print(mycelium_area)


for _ in range(int(input())):
    gx, gy, mx, my = map(int, input().split())
    mx = abs(mx - gx)
    my = abs(my - gy)
    solve(mx, my)
