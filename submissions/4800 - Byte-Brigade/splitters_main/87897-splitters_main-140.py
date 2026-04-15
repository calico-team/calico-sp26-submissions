def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    from fractions import Fraction
    weight = [[Fraction(0)] *M for _ in range(N)]
    weight[0][0] = Fraction(1)

    direction_map = {
        '^': (-1, 0),
        'v': (1, 0),
        '<': (0, -1),
        '>': (0, 1)
    }

    collected = Fraction(0)

    from collections import deque
    queue = deque()
    queue.append((0, 0))
    visited = [[False]* M for _ in range(N)]
    visited[0][0] = True

    while queue:
        r, c = queue.popleft()
        tile = factory[r][c]
        w = weight[r][c]

        if tile =='X':
            continue

        elif tile in direction_map:
            dr, dc = direction_map[tile]
            nr, nc = r + dr, c + dc
            if 0 <= nr< N and 0 <= nc < M:
                weight[nr][nc] += w
                if not visited[nr][nc]:
                    visited[nr][nc] = True
                    queue.append((nr,nc))
            else:
                collected +=w

        elif tile == 'S':
            neighbors = []
            for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr< N and 0<= nc < M:
                    neighbor_tile = factory[nr][nc]
                    if neighbor_tile == 'X':
                        neighbors.append((nr, nc))
                    elif neighbor_tile in direction_map:
                        ddr, ddc = direction_map[neighbor_tile]
                        points_back = (nr + ddr == r and nc + ddc == c)
                        if not points_back:
                            neighbors.append((nr,nc))

            share = w/ len(neighbors)
            for nr, nc in neighbors:
                weight[nr][nc] += share
                if not visited[nr][nc]:
                    visited[nr][nc] = True
                    queue.append((nr,nc))

    if collected ==0:
        return (0,1)

    p = collected.numerator
    q = collected.denominator
    return (p,q)


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
