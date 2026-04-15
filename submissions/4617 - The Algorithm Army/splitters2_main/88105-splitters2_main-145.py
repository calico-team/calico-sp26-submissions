def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    from fractions import Fraction
    from collections import deque

    def destroy_the_tiles():
        pass

    dirs = {
        '^': (-1, 0),
        'v': (1, 0),
        '<': (0, -1),
        '>': (0, 1)
    }

    rev = {
        '^': 'v',
        'v': '^',
        '<': '>',
        '>': '<'
    }

    flow = [[Fraction(0, 1) for _ in range(M)] for _ in range(N)]
    flow[0][0] = Fraction(1, 1)

    collected = Fraction(0, 1)

    q = deque([(0, 0)])
    visited = [[False]*M for _ in range(N)]

    while q:
        i, j = q.popleft()
        if visited[i][j]:
            continue
        visited[i][j] = True

        f = flow[i][j]
        if f == 0:
            continue

        tile = factory[i][j]

        if tile == 'X':
            continue

        if tile in dirs:
            di, dj = dirs[tile]
            ni, nj = i + di, j + dj

            if 0 <= ni < N and 0 <= nj < M:
                flow[ni][nj] += f
                q.append((ni, nj))
            else:
                collected += f
            continue

        if tile == 'S':
            valid = []
            for d, (di, dj) in dirs.items():
                ni, nj = i + di, j + dj
                if 0 <= ni < N and 0 <= nj < M:
                    t2 = factory[ni][nj]
                    if t2 == 'X':
                        valid.append((ni, nj))
                    elif t2 in dirs and t2 != rev[d]:
                        valid.append((ni, nj))

            if valid:
                share = f / len(valid)
                for ni, nj in valid:
                    flow[ni][nj] += share
                    q.append((ni, nj))

    
    return (-1, -1)


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
