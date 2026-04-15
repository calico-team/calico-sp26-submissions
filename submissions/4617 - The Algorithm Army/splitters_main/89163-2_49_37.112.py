from fractions import Fraction
import sys
sys.setrecursionlimit(10**7)

def solve(N, M, factory):

    dirs = {
        '^': (-1, 0),
        'v': (1, 0),
        '<': (0, -1),
        '>': (0, 1)
    }

    def inside(x, y):
        return 0 <= x < N and 0 <= y < M

    def node(x, y):
        return x * M + y

    # memo: probability of reaching "collection" from a cell
    memo = {}

    # detect cycles safety (though statement says none needed)
    visiting = set()

    def solve_cell(x, y):
        u = node(x, y)

        if u in memo:
            return memo[u]

        if (x, y) in visiting:
            return Fraction(0)  # safety fallback

        visiting.add((x, y))

        c = factory[x][y]

        # DESTROY TILE
        if c == 'X':
            visiting.remove((x, y))
            memo[u] = Fraction(0)
            return Fraction(0)

        # CONVEYOR
        if c in dirs:
            dx, dy = dirs[c]
            nx, ny = x + dx, y + dy

            visiting.remove((x, y))

            if not inside(nx, ny):
                return Fraction(1)  # collected
            return solve_cell(nx, ny)

        # SPLITTER
        if c == 'S':
            options = []

            for dx, dy in dirs.values():
                nx, ny = x + dx, y + dy
                if not inside(nx, ny):
                    continue

                nc = factory[nx][ny]

                if nc == 'X':
                    options.append(Fraction(0))
                elif nc in dirs:
                    bdx, bdy = dirs[nc]
                    # not pointing back
                    if nx + bdx == x and ny + bdy == y:
                        continue
                    options.append(solve_cell(nx, ny))

            visiting.remove((x, y))

            if not options:
                return Fraction(0)

            res = sum(options, Fraction(0)) / len(options)
            memo[u] = res
            return res

        visiting.remove((x, y))
        return Fraction(0)

    ans = solve_cell(0, 0)

    if ans == 0:
        return 0, 1

    return ans.numerator, ans.denominator


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input().strip() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)

if __name__ == "__main__":
    main()