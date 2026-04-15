def solve(L, W, E, R):
    triangle_area = 2 * (L + W)
    electricity_per_lap = triangle_area * R
    return E // electricity_per_lap

def read_your_input():
    T = int(input())
    for _ in range(T):
        L, W, E, R = map(int, input().split())
        print(solve(L, W, E, R))

read_your_input()