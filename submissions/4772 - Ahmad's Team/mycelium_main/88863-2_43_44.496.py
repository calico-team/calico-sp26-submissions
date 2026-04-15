def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Simulate the spread of grass (every 2 ticks) and mycelium (every 7 ticks)
    on an infinite grid starting from given positions.
    Return the total number of tiles mycelium will ever occupy.
    """
    # The grid is stored in a dictionary: (x, y) -> 1 (grass) or 2 (mycelium)
    grid = {}
    grid[(X_G, Y_G)] = 1
    grid[(X_M, Y_M)] = 2

    # To avoid simulating forever, we bound the region of interest.
    # The mycelium can never expand beyond the point where grass would
    # overtake it even without obstacles. A safe upper bound on Manhattan
    # distance from X_M, Y_M is given by 2/5 * D, where D is the Manhattan
    # distance between the two starting points.
    D = abs(X_G - X_M) + abs(Y_G - Y_M)
    max_dist = (2 * D + 4) // 5 + 5   # Add margin
    # Convert to a bounding box
    min_x = min(X_G, X_M) - max_dist - 2
    max_x = max(X_G, X_M) + max_dist + 2
    min_y = min(Y_G, Y_M) - max_dist - 2
    max_y = max(Y_G, Y_M) + max_dist + 2

    tick = 0
    # Continue until no more changes occur for a full cycle of 14 ticks
    # (LCM of 2 and 7) to ensure stability.
    last_change = 0
    while tick - last_change < 20:
        tick += 1
        changed = False

        new_grass = set()
        if tick % 2 == 0:
            for (x, y), v in list(grid.items()):
                if v == 1:
                    for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
                        nx, ny = x + dx, y + dy
                        # Stay inside reasonable bounds
                        if min_x <= nx <= max_x and min_y <= ny <= max_y:
                            if (nx, ny) not in grid or grid[(nx, ny)] == 0:
                                new_grass.add((nx, ny))

        new_myc = set()
        if tick % 7 == 0:
            for (x, y), v in list(grid.items()):
                if v == 2:
                    for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
                        nx, ny = x + dx, y + dy
                        if min_x <= nx <= max_x and min_y <= ny <= max_y:
                            if (nx, ny) not in grid or grid[(nx, ny)] == 0:
                                new_myc.add((nx, ny))

        # Apply grass first (grass wins ties)
        for pos in new_grass:
            if pos not in grid or grid[pos] != 1:
                grid[pos] = 1
                changed = True

        for pos in new_myc:
            if pos not in grid or grid[pos] == 0:
                grid[pos] = 2
                changed = True

        if changed:
            last_change = tick

    # Count mycelium tiles
    return sum(1 for v in grid.values() if v == 2)


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()