def solve(n: int, s1: list[str], s2: list[str]) -> tuple[int, int]:
    max_v = 0
    min_v = 0
    jugs_cave_image = []
    for i in range(n):
        r_i = 0
        for char in s1[i]:
            if char == '#':
                r_i += 1
        c_i = 0
        for char in s2[i]:
            if char == '#':
                c_i += 1
        max_v += r_i * c_i
        min_v += max(r_i, c_i)
    return max_v, min_v
def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        S1 = [input() for _ in range(N)]
        S2 = [input() for _ in range(N)]
        print(*solve(N, S1, S2))
if __name__ == '__main__':
    main()
