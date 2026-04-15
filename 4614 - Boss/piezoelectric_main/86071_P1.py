T = int(input())
for _ in range(T):
    L, W, E, R = map(int, input().split())
    tri_area = 2 * (L + W)
    electrcty = tri_area * R
    steps = E // electrcty
    print(steps)