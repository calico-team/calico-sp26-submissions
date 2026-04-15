tests = int(input())
for _ in range(tests):
    L, W, E, R = map(int,input().split())
    peri = (L+W) * 2
    steps = E // R
    print(steps // peri)