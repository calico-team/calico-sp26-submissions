def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.
    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    dir_map = {'^': (-1, 0), 'v': (1, 0), '<': (0, -1), '>': (0, 1)}

    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a

    queue = [(0, 0, 1, 1)]
    collected_p = 0
    collected_q = 1

    while queue:
        r, c, p, q = queue.pop(0)
        tile = factory[r][c]

        if tile == 'X':
            continue

        elif tile in dir_map:
            dr, dc = dir_map[tile]
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M:
                queue.append((nr, nc, p, q))
            else:
                new_p = collected_p * q + p * collected_q
                new_q = collected_q * q
                g = gcd(new_p, new_q)
                collected_p = new_p // g
                collected_q = new_q // g

        elif tile == 'S':
            valid_neighbors = []
            for direction in dir_map:
                dr, dc = dir_map[direction]
                nr, nc = r + dr, c + dc
                if 0 <= nr < N and 0 <= nc < M:
                    neighbor = factory[nr][nc]
                    if neighbor == 'X':
                        valid_neighbors.append((nr, nc))
                    elif neighbor in dir_map:
                        ndr, ndc = dir_map[neighbor]
                        if (nr + ndr, nc + ndc) != (r, c):
                            valid_neighbors.append((nr, nc))

            k = len(valid_neighbors)
            new_q = q * k
            g = gcd(p, new_q)
            new_p = p // g
            new_q = new_q // g
            for nr, nc in valid_neighbors:
                queue.append((nr, nc, new_p, new_q))

    return collected_p, collected_q


def main():
    T = int(input())
    for _ in range(T):
        line = input().strip()
        while line == '':
            line = input().strip()
        N, M = map(int, line.split())
        factory = []
        for i in range(N):
            row = input().strip()   # strip() added here
            factory.append(row)
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()