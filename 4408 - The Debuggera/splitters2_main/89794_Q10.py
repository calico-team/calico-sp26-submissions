from __future__ import annotations

import sys
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
    from collections import deque

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
    from collections import defaultdict

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
    from collections import defaultdict, deque

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


def den_pow(A: int, B: int) -> int:
    return (2**A) * (3**B)


def frac_to_triple(f: Fraction, max_a: int, max_b: int):
    for a in range(max_a + 1):
        for b in range(max_b + 1):
            d = den_pow(a, b)
            t = f * d
            if t.denominator == 1:
                n = int(t)
                if 0 <= n <= d and Fraction(n, d) == f:
                    return n, a, b
    return None


def pad_grid(g: list[str]) -> list[str]:
    if not g:
        return ["."]
    m = max(len(r) for r in g)
    return [r.ljust(m, ".") for r in g]


def empty_grid(r: int, c: int) -> list[list[str]]:
    return [["." for _ in range(c)] for _ in range(r)]


def paste(dst: list[list[str]], src: list[str], tr: int, tc: int) -> None:
    for i, row in enumerate(src):
        for j, ch in enumerate(row):
            if ch != ".":
                dst[tr + i][tc + j] = ch


def base_collect(width: int) -> list[str]:
    assert width >= 2
    return [">" * width]


def base_destroy() -> list[str]:
    return ["v", "X"]


def _feed_into_splitter(g: list[list[str]], sc: int) -> None:
    g[0][0] = "v"
    for c in range(0, sc):
        g[1][c] = ">"
    g[1][sc] = "S"


def _paste_child_right_of_splitter(g: list[list[str]], child: list[str], sc: int) -> None:
    g[1][sc + 1] = ">"
    paste(g, child, 1, sc + 2)


def compose_binary_shrink(child: list[str]) -> list[str]:
    child = pad_grid(child)
    hc, wc = len(child), len(child[0])
    sc = 3
    rows = max(hc + 2, 4)
    cols = max(wc + sc + 3, sc + 6)
    g = empty_grid(rows, cols)
    _feed_into_splitter(g, sc)
    g[2][sc] = "X"
    for c in range(sc + 2 + wc, cols):
        g[1][c] = ">"
    _paste_child_right_of_splitter(g, child, sc)
    return ["".join(row) for row in g]


def compose_binary_take(child: list[str]) -> list[str]:
    child = pad_grid(child)
    hc, wc = len(child), len(child[0])
    sc = 3
    rows = max(hc + 2, 4)
    cols = max(wc + sc + 3, sc + 6)
    g = empty_grid(rows, cols)
    _feed_into_splitter(g, sc)
    for r in range(2, rows):
        g[r][sc] = "v"
    for c in range(sc + 2 + wc, cols):
        g[1][c] = ">"
    _paste_child_right_of_splitter(g, child, sc)
    return ["".join(row) for row in g]


def compose_ternary_shrink(child: list[str]) -> list[str]:
    child = pad_grid(child)
    hc, wc = len(child), len(child[0])
    sc = 3
    rows = max(hc + 2, 4)
    cols = max(wc + sc + 3, sc + 6)
    g = empty_grid(rows, cols)
    _feed_into_splitter(g, sc)
    g[0][sc] = "X"
    g[2][sc] = "X"
    for c in range(sc + 2 + wc, cols):
        g[1][c] = ">"
    _paste_child_right_of_splitter(g, child, sc)
    return ["".join(row) for row in g]


def compose_ternary_two_full(child: list[str]) -> list[str]:
    child = pad_grid(child)
    hc, wc = len(child), len(child[0])
    sc = 3
    rows = max(hc + 2, 4)
    cols = max(wc + sc + 3, sc + 6)
    g = empty_grid(rows, cols)
    _feed_into_splitter(g, sc)
    g[0][sc] = "^"
    for r in range(2, rows):
        g[r][sc] = "v"
    for c in range(sc + 2 + wc, cols):
        g[1][c] = ">"
    _paste_child_right_of_splitter(g, child, sc)
    return ["".join(row) for row in g]


def compose_ternary_middle(child: list[str]) -> list[str]:
    child = pad_grid(child)
    hc, wc = len(child), len(child[0])
    sc = 3
    rows = max(hc + 2, 4)
    cols = max(wc + sc + 3, sc + 6)
    g = empty_grid(rows, cols)
    _feed_into_splitter(g, sc)
    g[0][sc] = "^"
    g[2][sc] = "X"
    for c in range(sc + 2 + wc, cols):
        g[1][c] = ">"
    _paste_child_right_of_splitter(g, child, sc)
    return ["".join(row) for row in g]


def build_factory(num: int, A: int, B: int) -> list[str]:
    den = den_pow(A, B)
    assert 0 <= num <= den

    if num == 0:
        return base_destroy()
    if num == den:
        return base_collect(2)

    if B > 0 and 3 * num <= den:
        return compose_ternary_shrink(build_factory(num, A, B - 1))
    if B > 0 and 3 * num >= 2 * den:
        n2 = num - 2 * (den // 3)
        return compose_ternary_two_full(build_factory(n2, A, B - 1))
    if A > 0 and 2 * num <= den:
        return compose_binary_shrink(build_factory(num, A - 1, B))
    if A > 0 and 2 * num > den:
        n2 = num - den // 2
        return compose_binary_take(build_factory(n2, A - 1, B))

    # Gap case: B>0, A==0, 1/3 < p < 2/3
    assert B > 0 and den < 3 * num < 2 * den and A == 0
    c = Fraction(3 * num - den, den)
    packed = frac_to_triple(c, A, B - 1)
    if packed is None:
        raise RuntimeError(f"cannot pack middle child {c} with bounds A={A}, B-1={B-1}")
    cn, ca, cb = packed
    return compose_ternary_middle(build_factory(cn, ca, cb))


def ensure_splitter_rules(grid: list[str]) -> None:
    N, M = len(grid), len(grid[0])
    for r in range(N):
        for c in range(M):
            if grid[r][c] != "S":
                continue
            assert 0 < r < N - 1 and 0 < c < M - 1, "S on border"
            for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                nr, nc = r + dr, c + dc
                if grid[nr][nc] == "S":
                    raise RuntimeError("adjacent splitters")


def main():
    data = sys.stdin.read().split()
    it = iter(data)
    T = int(next(it))
    out_lines = []
    for _ in range(T):
        P = int(next(it))
        A = int(next(it))
        B = int(next(it))
        den = den_pow(A, B)
        assert 1 <= P <= den
        g = build_factory(P, A, B)
        g = pad_grid(g)
        N, M = len(g), len(g[0])
        assert N * M <= 2000, f"grid too large {N}x{M}"
        ensure_splitter_rules(g)
        got = collected_fraction(g)
        want = Fraction(P, den)
        if got != want:
            raise SystemExit(f"wrong fraction want={want} got={got} for P={P} A={A} B={B}")
        out_lines.append(f"{N} {M}")
        out_lines.extend(g)
    sys.stdout.write("\n".join(out_lines) + "\n")


if __name__ == "__main__":
    main()
