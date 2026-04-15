def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    defeated=0
    for j in E:
        P -= j
        if P < 0:
            return "nah i'd lose"
        defeated += 1
        if defeated % K == 0:
            P += R
    return "nah i'd win"
def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()