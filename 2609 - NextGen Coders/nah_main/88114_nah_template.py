def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:

    cnt = 0  

    for i in range(N):
        P -= E[i]
        cnt += 1

        if P < 0:
            return "nah i'd lose"

        if cnt == K:
            P += R
            cnt = 0  # reset counter

    return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
