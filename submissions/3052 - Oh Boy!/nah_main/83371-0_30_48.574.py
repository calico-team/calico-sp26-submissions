def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    counter = 0
    win = True
    for op in E:
        P = P-op
        counter += 1
        if P < 0:
            win = False
        if counter == K:
            counter = 0
            P += R
    if win:
        return "nah i'd win"
    return "nah i'd lose"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
