def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    max_volume = 0
    min_volume = 0
    for y in range(N):
        a = S1[y].count("#")
        b = S2[y].count("#")
        max_volume += a + b
        min_volume += min(a, b)
    return max_volume, min_volume


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == "__main__":
    main()
