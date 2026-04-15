import sys


def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    """
    Return the maximal and minimal volume of the shape (in that order)
    
    N: max dimensions of shape
    S1: projection (shadow) in X-Z plane
    S2: projection (shadow) in Y-Z plane
    """
    jugs_cave_image = (S1, S2)

    max_volume = 0
    min_volume = 0

    for z in range(N):
        a = S1[z].count('#')
        b = S2[z].count('#')

        max_volume += a * b
        min_volume += max(a, b)

    return max_volume, min_volume


def main():
    data = sys.stdin.read().split()
    if not data:
        return

    it = iter(data)
    t = int(next(it))
    out = []
    for _ in range(t):
        n = int(next(it))
        s1 = [next(it) for _ in range(n)]
        s2 = [next(it) for _ in range(n)]
        mx, mn = solve(n, s1, s2)
        out.append(f"{mx} {mn}")

    sys.stdout.write("\n".join(out))


def read_your_input() -> list[tuple[int, list[str], list[str]]]:
    t = int(input())
    cases = []
    for _ in range(t):
        n = int(input())
        s1 = [input().strip() for _ in range(n)]
        s2 = [input().strip() for _ in range(n)]
        cases.append((n, s1, s2))
    return cases


if __name__ == '__main__':
    main()
