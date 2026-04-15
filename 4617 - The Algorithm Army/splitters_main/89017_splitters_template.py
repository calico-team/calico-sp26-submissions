def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
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

    # Map each cell to an index
    def inside(x, y):
        return 0 <= x < N and 0 <= y < M

    # Build graph: node -> list of (next_node, probability_weight)
    graph = {}
    collect_from = {}  # probability that goes out of grid from this node
    destroy_from = set()

    def node_id(x, y):
        return x * M + y

    for i in range(N):
        for j in range(M):
            c = factory[i][j]
            u = node_id(i, j)

            if c == 'X':
                graph[u] = []
                continue

            if c in dirs:
                dx, dy = dirs[c]
                ni, nj = i + dx, j + dy

                if inside(ni, nj):
                    v = node_id(ni, nj)
                    graph.setdefault(u, []).append((v, Fraction(1)))
                else:
                    collect_from[u] = Fraction(1)
                    graph.setdefault(u, [])

            elif c == 'S':
                candidates = []

                for dx, dy in dirs.values():
                    ni, nj = i + dx, j + dy
                    if not inside(ni, nj):
                        continue
                    nc = factory[ni][nj]

                    # valid if destroy tile OR conveyor not pointing back
                    if nc == 'X':
                        candidates.append(node_id(ni, nj))
                    elif nc in dirs:
                        bdx, bdy = dirs[nc]
                        # check if it points back to splitter
                        if ni + bdx == i and nj + bdy == j:
                            continue
                        candidates.append(node_id(ni, nj))

                graph[u] = [(v, Fraction(1, len(candidates))) for v in candidates]

            else:
                graph[u] = []

    # DFS topo sort (DAG guaranteed by statement)
    visited = set()
    order = []

    def dfs(u):
        visited.add(u)
        for v, _ in graph.get(u, []):
            if v not in visited:
                dfs(v)
        order.append(u)

    start = node_id(0, 0)
    dfs(start)

    # DP
    dp = {}

    for u in order:
        if u not in dp:
            dp[u] = Fraction(0)

    dp[start] = Fraction(1)

    collect = Fraction(0)

    for u in reversed(order):
        prob = dp[u]

        if u in collect_from:
            collect += prob * collect_from[u]

        for v, w in graph.get(u, []):
            dp[v] = dp.get(v, Fraction(0)) + prob * w

    if collect == 0:
        return 0, 1

    return collect.numerator, collect.denominator


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input().strip() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == "__main__":
    main()