def solve(N, P, R, K, curses):
    power = P
    for i in range(1, N + 1):
        power -= curses[i - 1]
        if power < 0:
            return "nah i'd lose"
        if i % K == 0:
            power += R
    return "nah i'd win"


def main():
    T = int(input())
    for _ in range(T):
        N, P, R, K = map(int, input().split())
        curses = list(map(int, input().split()))
        print(solve(N, P, R, K, curses))


if __name__ == "__main__":
    main()
