T = int(input())
for i in range(T):
    floors = int(input())
    top_floor = list(map(int, input().split()))
    bottom_floor = top_floor
    for i in range(1, len(top_floor)):
        if (top_floor[i] + bottom_floor[i - 1]) % 2 == 1:
            bottom_floor[i] = int((top_floor[i] + bottom_floor[i - 1]) // 2) + 1
        else:
            bottom_floor[i] = int(((top_floor[i] + bottom_floor[i - 1]) // 2) - 1)
    print(*bottom_floor)