T = int(input())

for _ in range(T):
    xg, yg, xm, ym = map(int, input().split())

    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    all_occupied = {(xg, yg): 'G', (xm, ym): 'M'}

    green_frontier = {(xg, yg)}
    shroom_frontier = {(xm, ym)}

    create_voronoi_7 = 1
    current_tick = 0

    while shroom_frontier:
        current_tick += 1

        if current_tick % 2 == 0:
            fresh_grass = set()
            for gx, gy in green_frontier:
                for step_x, step_y in directions:
                    neighbor = (gx + step_x, gy + step_y)
                    if neighbor not in all_occupied:
                        fresh_grass.add(neighbor)
            for tile in fresh_grass:
                all_occupied[tile] = 'G'
            green_frontier = fresh_grass

        if current_tick % 7 == 0:
            fresh_shroom = set()
            for mx, my in shroom_frontier:
                for step_x, step_y in directions:
                    neighbor = (mx + step_x, my + step_y)
                    if neighbor not in all_occupied:
                        fresh_shroom.add(neighbor)
            for tile in fresh_shroom:
                all_occupied[tile] = 'M'
            shroom_frontier = fresh_shroom
            create_voronoi_7 += len(fresh_shroom)

    print(create_voronoi_7)

def read_your_input():
    return map(int, input().split())