def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    grass = {(X_G, Y_G)}
    mycelium = {(X_M, Y_M)}
    last_new = 0
    tick = 0
    max_ticks = 10000
    
    while tick <= max_ticks:
        tick += 1
        new_grass = set()
        new_mycelium = set()
        if tick % 2 == 0:
            for (x, y) in grass:
                for nx, ny in [(x+1,y), (x-1,y), (x,y+1), (x,y-1)]:
                    if (nx, ny) not in grass and (nx, ny) not in mycelium:
                        new_grass.add((nx, ny))
        if tick % 7 == 0:
            for (x, y) in mycelium:
                for nx, ny in [(x+1,y), (x-1,y), (x,y+1), (x,y-1)]:
                    if (nx, ny) not in grass and (nx, ny) not in mycelium and (nx, ny) not in new_grass:
                        new_mycelium.add((nx, ny))
        grass.update(new_grass)
        mycelium.update(new_mycelium)
        if not new_mycelium:
            last_new += 1
        else:
            last_new = 0
        if last_new > 100:
            break
    
    return len(mycelium)


def read_your_input():
    import sys
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    T = int(next(it))
    out_lines = []
    for _ in range(T):
        XG = int(next(it)); YG = int(next(it)); XM = int(next(it)); YM = int(next(it))
        out_lines.append(str(solve(XG, YG, XM, YM)))
    sys.stdout.write("\n".join(out_lines))


def main():
    T = int(input())
    for _ in range(T):
        X_G, Y_G, X_M, Y_M = map(int, input().split())
        print(solve(X_G, Y_G, X_M, Y_M))


if __name__ == '__main__':
    main()