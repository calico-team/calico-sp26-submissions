def count_mycelium_tiles(xg, yg, xm, ym):
    # We will count all integer points where:
    # 7 * dist_M < 2 * dist_G
    # Using Manhattan distance

    visited = set()
    queue = [(xm, ym)]
    visited.add((xm, ym))

    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    total_mycelium = 0

    while queue:
        x, y = queue.pop(0)

        # Distances
        dist_m = abs(x - xm) + abs(y - ym)
        dist_g = abs(x - xg) + abs(y - yg)

        # Check if mycelium reaches first
        if 7 * dist_m < 2 * dist_g:
            total_mycelium += 1

            # Expand further from this tile
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if (nx, ny) not in visited:
                    visited.add((nx, ny))
                    queue.append((nx, ny))

    return total_mycelium


# Main input handling
T = int(input())

for _ in range(T):
    xg, yg, xm, ym = map(int, input().split())
    print(count_mycelium_tiles(xg, yg, xm, ym))


# Helper function (as required)
def read_your_input():
    return map(int, input().split())