def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
   direction_map = {'^':(-1,0),'v':(1,0),'<':(0,-1),'>' :(0,1)}

    def get_targets(r,c):
        tile = factory[r][c]
        if tile in ('.' ,'X'):
            return []
        elif tile in direction_map:
            dr, dc = direction_map[tile]
            nr, nc = r +dr, c+ dc
            if 0 <=nr <N and 0<= nc < M:
                return [(nr,nc)]
            else:
                return [(-1,-1 )]  # exits grid
        elif tile =='S':
            neighbors = []
            for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < M:
                    nt = factory[nr][nc]
                    if nt == 'X':
                        neighbors.append((nr, nc))
                    elif nt in direction_map:
                        ddr, ddc = direction_map[nt]
                        if not (nr + ddr == r and nc + ddc == c):
                            neighbors.append((nr, nc))
            return neighbors
        return []

    reachable =set()
    bfs = deque([(0,0)])
    reachable.add(( 0,0))
    while bfs:
        r, c = bfs.popleft()
        for nr, nc in get_targets(r,c):
            if (nr, nc) != (-1,-1) and (nr, nc) not in reachable:
                reachable.add((nr, nc))
                bfs.append((nr, nc))

    in_deg = defaultdict(int)
    for r, c in reachable:
        for nr, nc in get_targets(r, c):
            if (nr, nc) != (-1, -1):
                in_deg[(nr, nc)] += 1

    topo_queue = deque()
    for r, c in reachable:
        if in_deg[(r, c)] == 0:
            topo_queue.append((r, c))

    weight =defaultdict(lambda: Fraction(0))
    weight[(0, 0)] =Fraction(1)
    collected = Fraction(0)

    while topo_queue:
        r, c = topo_queue.popleft()
        tile = factory[r][c]
        w = weight[(r, c)]

        if tile == 'X':
            pass  
        elif tile in direction_map:
            targets = get_targets(r, c)
            if targets[0] == (-1, -1):
                collected += w
            else:
                nr, nc = targets[0]
                weight[(nr, nc)] += w
                in_deg[(nr, nc)] -= 1
                if in_deg[(nr, nc)] == 0:
                    topo_queue.append((nr, nc))
        elif tile == 'S':
            targets = get_targets(r, c)
            share = w / len(targets)
            for nr, nc in targets:
                weight[(nr, nc)] += share
                in_deg[(nr, nc)] -= 1
                if in_deg[(nr, nc)] == 0:
                    topo_queue.append((nr, nc))

    if collected == 0:
        return (0, 1)
    return (collected.numerator, collected.denominator)


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
