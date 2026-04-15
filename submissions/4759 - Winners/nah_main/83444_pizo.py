def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    power = P
    counter = 0
    for i in E:
        power -= i
        if power < 0:
            return "nah i'd lose"
        counter += 1
        if counter == K:
            power += R
            counter = 0
    return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
