T = int(input())
for _ in range(T):
    L, W, E, R = map(int, input().split())
    perameter = 2 * (L + W)
    every_lap = perameter * R
    print(E // every_lap)