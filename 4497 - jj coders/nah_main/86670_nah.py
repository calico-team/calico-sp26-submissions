def solve(N: int, P: int, R: int, K: int, E: list[int]) -> str:
    used_since = K  # allows immediate use at start

    for i in range(N):
        while True:
            # If can defeat normally
            if P >= E[i]:
                P -= E[i]
                used_since += 1
                break

            # Try to heal if cooldown allows
            if used_since >= K:
                P += R
                used_since = 0
            else:
                return "nah i'd lose"

    return "nah i'd win"


def main() -> None:
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        E = list(map(int, input().split()))
        print(solve(N, P, R, K, E))


if __name__ == "__main__":
    main()