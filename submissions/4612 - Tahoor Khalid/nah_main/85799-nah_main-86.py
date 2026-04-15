def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    gojoPower = P
    count = 0

    for curse in range(N):
        gojoPower -= E[curse]
        count += 1

        if gojoPower < 0:
            return "nah i’d lose"

        if count == K:
            gojoPower += R
            count = 0

    return "nah i’d win"


def main() -> None:
    T = int(input())
    for n in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
