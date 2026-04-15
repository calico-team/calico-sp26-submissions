def solve(N: int, S1: list[str], S2: list[str]) -> tuple[int, int]:
    jugs_cave_image = None
    max_vol = 0
    min_vol = 0
    for z in range(N):
        a = S1[z].count('#')
        b = S2[z].count('#')
        max_vol += a * b
        min_vol += max(a, b)
    return max_vol, min_vol


def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))


if __name__ == '__main__':
    main()