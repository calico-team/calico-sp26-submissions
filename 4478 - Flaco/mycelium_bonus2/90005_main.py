import sys


def ints_from_stdin():
    data = sys.stdin.buffer.read()
    num = 0
    sign = 1
    in_num = False

    for b in data:
        if 48 <= b <= 57:
            num = num * 10 + (b - 48)
            in_num = True
        elif b == 45:
            sign = -1
        elif in_num:
            yield sign * num
            num = 0
            sign = 1
            in_num = False

    if in_num:
        yield sign * num


def build_candidates(frontier, occupied):
    candidates = set()
    next_frontier = set()

    for x, y in frontier:
        has_empty_neighbor = False

        p = (x + 1, y)
        if p not in occupied:
            has_empty_neighbor = True
            candidates.add(p)

        p = (x - 1, y)
        if p not in occupied:
            has_empty_neighbor = True
            candidates.add(p)

        p = (x, y + 1)
        if p not in occupied:
            has_empty_neighbor = True
            candidates.add(p)

        p = (x, y - 1)
        if p not in occupied:
            has_empty_neighbor = True
            candidates.add(p)

        if has_empty_neighbor:
            next_frontier.add((x, y))

    return candidates, next_frontier


def solve_case(xg, yg, xm, ym):
    occupied = {(xg, yg), (xm, ym)}

    grass_frontier = {(xg, yg)}
    mycelium_frontier = {(xm, ym)}

    mycelium_total = 1
    tick = 0

    while True:
        tick += 1

        grass_tick = (tick % 2 == 0)
        mycelium_tick = (tick % 7 == 0)

        grass_candidates = set()
        mycelium_candidates = set()

        next_grass_frontier = grass_frontier
        next_mycelium_frontier = mycelium_frontier

        if grass_tick:
            grass_candidates, next_grass_frontier = build_candidates(grass_frontier, occupied)

        if mycelium_tick:
            mycelium_candidates, next_mycelium_frontier = build_candidates(mycelium_frontier, occupied)

        if grass_tick and mycelium_tick:
            new_grass = grass_candidates
            new_mycelium = mycelium_candidates - grass_candidates
        elif grass_tick:
            new_grass = grass_candidates
            new_mycelium = set()
        elif mycelium_tick:
            new_grass = set()
            new_mycelium = mycelium_candidates
        else:
            continue

        if new_grass:
            occupied.update(new_grass)
        if new_mycelium:
            occupied.update(new_mycelium)
            mycelium_total += len(new_mycelium)

        if grass_tick:
            grass_frontier = next_grass_frontier
            if new_grass:
                grass_frontier |= new_grass

        if mycelium_tick:
            mycelium_frontier = next_mycelium_frontier
            if new_mycelium:
                mycelium_frontier |= new_mycelium
            else:
                return mycelium_total


def main():
    it = iter(ints_from_stdin())

    try:
        t = next(it)
    except StopIteration:
        return

    out = []

    for _ in range(t):
        xg = next(it)
        yg = next(it)
        xm = next(it)
        ym = next(it)
        out.append(str(solve_case(xg, yg, xm, ym)))

    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
