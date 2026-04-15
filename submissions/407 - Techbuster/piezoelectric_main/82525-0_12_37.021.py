import sys
input = sys.stdin.readline

def solve(L, W, E, R):
    perimeter = 2 * (L + W)
    energy_per_lap = perimeter * R
    return E // energy_per_lap

def main():
    T = int(input())
    for _ in range(T):
        L, W, E, R = map(int, input().split())
        print(solve(L, W, E, R))

main()