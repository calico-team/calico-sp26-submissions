import sys
input = sys.stdin.readline


def solve(L, W, E, R):
    perimeter = 2 * (L + W)
    electricity_per_lap = perimeter * R
    return E // electricity_per_lap


def main():
    T = int(input())
    for _ in range(T):
        L, W, E, R = map(int, input().split())
        print(solve(L, W, E, R))


if __name__ == '__main__':
    main()
