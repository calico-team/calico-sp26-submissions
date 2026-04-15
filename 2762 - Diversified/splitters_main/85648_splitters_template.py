def solve(N, M, factory):
    import math
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    Emuns = {'^': (-1, 0), 'v': (1, 0), '<': (0, -1), '>': (0, 1)}
    vm = list(Emuns.values())

    def greatest(a, b):
        g = math.gcd(a, b)
        return a // g, b // g

    def add(a, b, c, d):
        return b * c + a * d, b * d

    # YOUR CODE HERE
    factory = [row.lower() for row in factory]
    memory = {}

    def memadd(r, c):
        if (r, c) in memory:
            return memory[(r, c)]

        t = factory[r][c]

        if t == '.':
            return (0, 1)

        if t == "x":
            memory[(r, c)] = (0, 1)
            return (0, 1)

        if t in Emuns:
            dr, dc = Emuns[t]
            nr, nc = r + dr, c + dc
            if not (0 <= nr < N and 0 <= nc < M):
                memory[(r, c)] = (1, 1)
            else:
                memory[(r, c)] = memadd(nr, nc)
            return memory[(r, c)]


        num, den, cnt = 0, 1, 0

        for dr, dc in vm:
            nr, nc = r + dr, c + dc
            if not (0 <= nr < N and 0 <= nc < M):
                continue

            nt = factory[nr][nc]

            if nt == "x":
                num, den = add(num, den, 0, 1)
                cnt += 1
            elif nt in Emuns:
                br, bc = Emuns[nt]
                if nr + br == r and nc + bc == c:
                    continue
                a, b = memadd(nr, nc)
                num, den = add(num, den, a, b)
                cnt += 1

        if cnt == 0:
            memory[(r, c)] = (0, 1)
        else:
            memory[(r, c)] = greatest(num, den * cnt)

        return memory[(r, c)]

    return memadd(0, 0)


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
