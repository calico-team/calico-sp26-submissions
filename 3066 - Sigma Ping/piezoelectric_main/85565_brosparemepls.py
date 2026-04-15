T = int(input())
for _ in range(T):
    L, W, E, R = map(int, input().split())
    print(E // (2 * (L + W) * R))