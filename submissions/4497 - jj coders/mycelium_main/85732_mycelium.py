def solve(X_G: int, Y_G: int, X_M: int, Y_M: int) -> int:
    # Simulate the competitive BFS
    state = {(X_G, Y_G): 'grass', (X_M, Y_M): 'mycelium'}
    mycelium_tiles = {(X_M, Y_M)}
    grass_tiles = {(X_G, Y_G)}
    stable_count = 0
    last_myc = 0
    
    for tick in range(1, 1000000):
        new_mycelium = set()
        new_grass = set()
        if tick % 2 == 0:
            for (x, y) in grass_tiles:
                for dx, dy in [(0,1),(0,-1),(1,0),(-1,0)]:
                    pos = (x+dx, y+dy)
                    if pos not in state:
                        new_grass.add(pos)
        if tick % 7 == 0:
            for (x, y) in mycelium_tiles:
                for dx, dy in [(0,1),(0,-1),(1,0),(-1,0)]:
                    pos = (x+dx, y+dy)
                    if pos not in state:
                        new_mycelium.add(pos)
        conflict = new_grass & new_mycelium
        for pos in new_grass | conflict:
            state[pos] = 'grass'
            grass_tiles.add(pos)
        for pos in new_mycelium - conflict:
            state[pos] = 'mycelium'
            mycelium_tiles.add(pos)
        if tick % 7 == 0:
            cur = len(mycelium_tiles)
            if cur == last_myc:
                stable_count += 1
                if stable_count >= 5:
                    break
            else:
                stable_count = 0
            last_myc = cur
    
    return len(mycelium_tiles)