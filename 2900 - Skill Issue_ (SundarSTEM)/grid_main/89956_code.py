t = int(input())
for _ in range(t):
    n = int(input())
    the_two_tower_heights = list(map(int, input().split()))
    the_two_tower_heights.sort()
    x = the_two_tower_heights[n // 2]
    print(*([x] * n))