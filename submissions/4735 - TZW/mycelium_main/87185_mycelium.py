T = int(input())

for _ in range(T):
    XG, YG, XM, YM = map(int, input().split())

    bestG = {}
    
    frontier = [(XG, YG, 0)]
    i = 0
    while i < len(frontier):
        x, y, t = frontier[i]
        i += 1

        if (x, y) in bestG and bestG[(x, y)] <= t:
            continue
        bestG[(x, y)] = t

        for dx, dy in ((1,0),(-1,0),(0,1),(0,-1)):
            frontier.append((x+dx, y+dy, t+2))

        if t > 200: 
            break

    frontier = [(XM, YM, 0)]
    visited = set()
    ans = 0
    i = 0

    while i < len(frontier):
        x, y, t = frontier[i]
        i += 1

        if (x, y) in visited:
            continue
        visited.add((x, y))

        if x in bestG and y in bestG:
            pass

        if (x, y) not in bestG or 7*t < bestG[(x, y)]:
            ans += 1
            for dx, dy in ((1,0),(-1,0),(0,1),(0,-1)):
                frontier.append((x+dx, y+dy, t+7))

        if t > 200:
            continue

    print(ans)
