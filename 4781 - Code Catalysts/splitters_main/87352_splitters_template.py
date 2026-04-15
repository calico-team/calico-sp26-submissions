from fractions import Fraction


def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    grid = [list(row) for row in factory]

    dr = {"^": -1, "v": 1, "<": 0, ">": 0}
    dc = {"^": 0, "v": 0, "<": -1, ">": 1}

    def valid_splitter_neighbor(sr, sc, nr, nc):
        ch = grid[nr][nc]
        if ch == "X":
            return True
        if ch in "^v<>":
            ndr, ndc = dr[ch], dc[ch]
            return (nr + ndr, nc + ndc) != (sr, sc)
        return False

    def next_cell(r, c):
        ch = grid[r][c]
        if ch not in "^v<>":
            return None
        nr, nc = r + dr[ch], c + dc[ch]
        if 0 <= nr < N and 0 <= nc < M:
            return nr, nc
        return None

    flow = [[Fraction(0) for _ in range(M)] for _ in range(N)]
    flow[0][0] = Fraction(1)

    collected = Fraction(0)

    while True:
        moved = False
        new_flow = [[Fraction(0) for _ in range(M)] for _ in range(N)]

        for r in range(N):
            for c in range(M):
                f = flow[r][c]
                if f == 0:
                    continue

                ch = grid[r][c]

                if ch == "X":
                    moved = True
                    continue

                if ch in "^v<>":
                    nxt = next_cell(r, c)
                    if nxt is None:
                        collected += f
                    else:
                        nr, nc = nxt
                        new_flow[nr][nc] += f
                    moved = True
                    continue

                if ch == "S":
                    neigh = []
                    for nr, nc in ((r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)):
                        if 0 <= nr < N and 0 <= nc < M and valid_splitter_neighbor(r, c, nr, nc):
                            neigh.append((nr, nc))
                    share = f / len(neigh)
                    for nr, nc in neigh:
                        new_flow[nr][nc] += share
                    moved = True
                    continue

                assert False, f"flow at empty cell ({r},{c})"

        flow = new_flow
        if not moved and all(flow[r][c] == 0 for r in range(N) for c in range(M)):
            break
        if not moved:
            break

    return collected.numerator, collected.denominator


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == "__main__":
    main()
