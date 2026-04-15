def solve(N, P, R, K, E):
    dy_power = P  
    
    for i in range(N):
        dy_power = dy_power - E[i]
        if dy_power < 0:
            return "nah i'd lose"
        if (i + 1) % K == 0:
            dy_power = dy_power + R
    
    return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()
