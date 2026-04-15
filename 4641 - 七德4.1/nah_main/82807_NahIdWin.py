def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    power_level = P
    ok = True
    for j in range(N):
        if power_level >= E[j]:
            power_level -= E[j]
            if (j+1) % K == 0:
                power_level += R
        else:
            return("nah i’d lose")
    if ok and power_level >= 0:
        return("nah i’d win")
    else:
        return("nah i’d lose")


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
