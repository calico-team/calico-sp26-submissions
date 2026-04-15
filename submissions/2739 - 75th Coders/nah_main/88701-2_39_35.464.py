def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    crnt_pwer = P

    for i in range(N):
        crnt_pwer -= E[i]

        if crnt_pwer < 0:
            return "naah i'd lose"

        if (i + 1) % K == 0:
            crnt_pwer += R

    return "naah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()