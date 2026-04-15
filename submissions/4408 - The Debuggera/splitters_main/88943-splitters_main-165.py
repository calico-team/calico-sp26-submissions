import sys
from collections import defaultdict, deque
from fractions import Fraction


DIR = {"^": (-1, 0), "v": (1, 0), "<": (0, -1), ">": (0, 1)}


def valid_splitter_neighbors(grid, N, M, r, c):
    out = []
    for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
        nr, nc = r + dr, c + dc
        if not (0 <= nr < N and 0 <= nc < M):
            continue
        ch = grid[nr][nc]
        if ch == ".":
            continue
        if ch == "X":
            out.append((nr, nc))
        elif ch in DIR:
            ndr, ndc = DIR[ch]
            if nr + ndr == r and nc + ndc == c:
                continue
            out.append((nr, nc))
    return out


def reachable_from(grid, N, M):
    if grid[0][0] == ".":
        return set()
    seen = {(0, 0)}
    dq = deque([(0, 0)])
    while dq:
        r, c = dq.popleft()
        ch = grid[r][c]
        if ch == "X":
            continue
        if ch in DIR:
            dr, dc = DIR[ch]
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M and grid[nr][nc] != ".":
                if (nr, nc) not in seen:
                    seen.add((nr, nc))
                    dq.append((nr, nc))
        elif ch == "S":
            for nr, nc in valid_splitter_neighbors(grid, N, M, r, c):
                if (nr, nc) not in seen:
                    seen.add((nr, nc))
                    dq.append((nr, nc))
    return seen


def build_graph(grid, N, M, reachable):
    graph = defaultdict(list)
    indeg = defaultdict(int)

    for r, c in reachable:
        ch = grid[r][c]
        if ch == "X":
            continue
        if ch in DIR:
            dr, dc = DIR[ch]
            nr, nc = r + dr, c + dc
            if 0 <= nr < N and 0 <= nc < M and (nr, nc) in reachable:
                graph[(r, c)].append(((nr, nc), Fraction(1, 1)))
                indeg[(nr, nc)] += 1
            else:
                graph[(r, c)].append((None, Fraction(1, 1)))
        elif ch == "S":
            nbrs = valid_splitter_neighbors(grid, N, M, r, c)
            k = len(nbrs)
            if k == 0:
                continue
            w = Fraction(1, k)
            for nr, nc in nbrs:
                if (nr, nc) in reachable:
                    graph[(r, c)].append(((nr, nc), w))
                    indeg[(nr, nc)] += 1
                else:
                    graph[(r, c)].append((None, w))
    return graph, indeg


def collected_fraction(grid):
    N, M = len(grid), len(grid[0])
    reach = reachable_from(grid, N, M)
    graph, indeg = build_graph(grid, N, M, reach)

    inflow = defaultdict(Fraction)
    inflow[(0, 0)] = Fraction(1, 1)
    collected = Fraction(0, 1)

    remain = defaultdict(int)
    for k, v in indeg.items():
        remain[k] = v

    q = deque()
    for cell in reach:
        if remain[cell] == 0:
            q.append(cell)

    while q:
        u = q.popleft()
        f = inflow[u]
        for v, w in graph[u]:
            add = f * w
            if v is None:
                collected += add
            else:
                inflow[v] += add
                remain[v] -= 1
                if remain[v] == 0:
                    q.append(v)

    return collected


def main():
    data = sys.stdin.read().split()
    it = iter(data)
    T = int(next(it))
    out = []
    for _ in range(T):
        N = int(next(it))
        M = int(next(it))
        grid = [list(next(it)) for _ in range(N)]
        ans = collected_fraction(grid)
        out.append(f"{ans.numerator} {ans.denominator}")
    sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
