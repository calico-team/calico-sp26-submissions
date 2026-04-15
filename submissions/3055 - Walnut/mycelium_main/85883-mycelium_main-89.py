tests = int(input())
for i in range(tests):
    grassx, grassy, myceliumx, myceliumy = map(int, input().split())
    grass = {(grassx, grassy)}
    mold = {(myceliumx, myceliumy)}
    seen = {(grassx, grassy): 1, (myceliumx, myceliumy): 2}
    tick = 0
    still = 0
    previous = 1
    while still < 30:
        tick += 1
        grassspread = set()
        myceliumspread = set()
        if tick % 2 == 0:
            for x, y in grass:
                for changex, changey in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                    spot = (x + changex, y + changey)
                    if spot not in seen:
                        grassspread.add(spot)
        if tick % 7 == 0:
            for x, y in mold:
                for changex, changey in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                    spot = (x + changex, y + changey)
                    if spot not in seen:
                        myceliumspread.add(spot)
        for spot in grassspread:
            seen[spot] = 1
        fresh = myceliumspread - grassspread
        for spot in fresh:
            seen[spot] = 2
        grass |= grassspread
        mold |= fresh
        if len(mold) == previous:
            still += 1
        else:
            still = 0
            previous = len(mold)
    print(len(mold))