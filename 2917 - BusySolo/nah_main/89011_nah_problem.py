def solve(N, P, R, K, E):
    power_level = P  
    
    for i in range(N):
        power_level = power_level - E[i]
        if power_level < 0:
            return "nah i'd lose"
        if (i + 1) % K == 0:
            power_level = power_level + R
    
    return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
