def beside(x,y):
    return [(x-1,y),(x+1,y),(x,y+1),(x,y-1)]

def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    """
    Return the total number of tiles mycelium will ever occupy.

    X_G: x-coordinate of grass starting position
    Y_G: y-coordinate of grass starting position
    X_M: x-coordinate of mycelium starting position
    Y_M: y-coordinate of mycelium starting position
    """
    grass_occupied = {(X_G, Y_G)}
    m_occupied = {(X_M, Y_M)}

    last_g = {(X_G, Y_G)}
    last_m = {(X_M, Y_M)}

    tick = 0
    while True:
        tick+=1
        if tick % 2 == 0:
            next_g = set()

            for x, y in last_g:
                next_grass_tile = beside(x, y)
                for nx, ny in next_grass_tile:
                    if (nx, ny) not in grass_occupied:
                        next_g.add((nx, ny))

            for pos in next_g:
                grass_occupied.add(pos)
            last_g = next_g
        if tick % 7 == 0:
            next_m = set()
            for x, y in last_m:
                next_m_tile = beside(x, y)
                for nx, ny in next_m_tile:
                    if (nx, ny) not in m_occupied and (nx,ny) not in grass_occupied:
                        next_m.add((nx, ny))
            for pos in next_m:
                m_occupied.add(pos)
            last_m = next_m
            if len(next_m)==0:
                break
    return len(m_occupied)

def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()
