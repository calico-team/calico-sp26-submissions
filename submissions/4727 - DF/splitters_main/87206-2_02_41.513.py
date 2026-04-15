from fractions import Fraction
from collections import deque, defaultdict


def solve(N, M, factory):
    DIRS = {'^': (-1, 0), 'v': (1, 0), '<': (0, -1), '>': (0, 1)}

    def get_destinations(r, c):
        tile = factory[r][c]
        if tile in ('X', '.'):
            return []
        if tile in DIRS:
            dr, dc = DIRS[tile]
            nr, nc = r + dr, c + dc
            return [(nr, nc)] if 0 <= nr < N and 0 <= nc < M else []
        if tile == 'S':
            valid = []
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < M:
                    adj = factory[nr][nc]
                    if adj == 'X':
                        valid.append((nr, nc))
                    elif adj in DIRS:
                        adjdr, adjdc = DIRS[adj]
                        if (nr + adjdr, nc + adjdc) != (r, c):
                            valid.append((nr, nc))
            return valid
        return []

    reachable = set()
    queue = deque([(0, 0)])
    reachable.add((0, 0))
    while queue:
        r, c = queue.popleft()
        for nr, nc in get_destinations(r, c):
            if (nr, nc) not in reachable:
                reachable.add((nr, nc))
                queue.append((nr, nc))

    in_deg = defaultdict(int)
    edges = defaultdict(list)
    for r, c in reachable:
        for nr, nc in get_destinations(r, c):
            if (nr, nc) in reachable:
                edges[(r, c)].append((nr, nc))
                in_deg[(nr, nc)] += 1

    q = deque()
    for node in reachable:
        if in_deg[node] == 0:
            q.append(node)

    topo = []
    while q:
        node = q.popleft()
        topo.append(node)
        for nb in edges[node]:
            in_deg[nb] -= 1
            if in_deg[nb] == 0:
                q.append(nb)

    prob = defaultdict(Fraction)
    prob[(0, 0)] = Fraction(1)
    collected = Fraction(0)

    for r, c in topo:
        p = prob[(r, c)]
        if p == 0:
            continue
        tile = factory[r][c]
        dests = get_destinations(r, c)
        if tile == 'X':
            pass
        elif tile in DIRS:
            dr, dc = DIRS[tile]
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M:
                prob[(nr, nc)] += p
            else:
                collected += p
        elif tile == 'S':
            each = p / len(dests)
            for nr, nc in dests:
                prob[(nr, nc)] += each

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
