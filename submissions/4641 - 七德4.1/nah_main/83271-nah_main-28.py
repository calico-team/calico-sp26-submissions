def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    power_level = P
    for j in range(1,N+1):
        if power_level >= E[j-1]:
            power_level -= E[j-1]
            if (j) % K == 0:
                power_level += R
        else:
            return("nah i'd lose")
    return("nah i'd win")



def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
