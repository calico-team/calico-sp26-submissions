import sys

def solve():
    data = sys.stdin.read().split()
    idx = 0
    T = int(data[idx]); idx += 1

    dirs = [(0,1),(0,-1),(1,0),(-1,0)]

    for _ in range(T):
        xg, yg, xm, ym = int(data[idx]), int(data[idx+1]), int(data[idx+2]), int(data[idx+3])
        idx += 4

        create_voronoi_7 = 0

        grass = {(xg, yg)}
        mycelium = {(xm, ym)}
        grass_frontier = [(xg, yg)]
        mycelium_frontier = [(xm, ym)]

        grass_exp = 0
        myc_exp = 0

        while mycelium_frontier:
            next_g = 2 * (grass_exp + 1)
            next_m = 7 * (myc_exp + 1)

            if next_g < next_m:
                new_f = []
                for x, y in grass_frontier:
                    for dx, dy in dirs:
                        nx, ny = x + dx, y + dy
                        if (nx, ny) not in grass and (nx, ny) not in mycelium:
                            grass.add((nx, ny))
                            new_f.append((nx, ny))
                grass_frontier = new_f
                grass_exp += 1

            elif next_m < next_g:
                new_f = []
                for x, y in mycelium_frontier:
                    for dx, dy in dirs:
                        nx, ny = x + dx, y + dy
                        if (nx, ny) not in grass and (nx, ny) not in mycelium:
                            mycelium.add((nx, ny))
                            new_f.append((nx, ny))
                mycelium_frontier = new_f
                myc_exp += 1

            else:
                # Both expand simultaneously — ties go to grass
                new_g = set()
                for x, y in grass_frontier:
                    for dx, dy in dirs:
                        nx, ny = x + dx, y + dy
                        if (nx, ny) not in grass and (nx, ny) not in mycelium:
                            new_g.add((nx, ny))

                new_m = set()
                for x, y in mycelium_frontier:
                    for dx, dy in dirs:
                        nx, ny = x + dx, y + dy
                        if (nx, ny) not in grass and (nx, ny) not in mycelium:
                            new_m.add((nx, ny))

                actual_m = new_m - new_g
                grass.update(new_g)
                mycelium.update(actual_m)
                grass_frontier = list(new_g)
                mycelium_frontier = list(actual_m)
                grass_exp += 1
                myc_exp += 1

        print(len(mycelium))

def read_your_input():
    return sys.stdin.read()

if __name__ == "__main__":
    solve()
