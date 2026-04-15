def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    jugs_cave_image = None

    max_vol = 0
    min_vol = 0

    for z in range(N):
        xs = 0
        ys = 0

        for x in range(N):
            if S1[z][x] == '#':
                xs += 1

        for y in range(N):
            if S2[z][y] == '#':
                ys += 1

        max_vol += xs * ys
        min_vol += max(xs, ys)

    return max_vol, min_vol


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == "__main__":
    main()
