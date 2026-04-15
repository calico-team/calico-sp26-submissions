T = int(input())
for _ in range(T):
    L, W, E, R = map(int, input().split())
    perimeter = 2 * (L + W)
    lap = R * perimeter 
    print(E // lap)