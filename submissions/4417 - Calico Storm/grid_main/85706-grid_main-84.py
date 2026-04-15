T = int(input())

for _ in range(T):
    n = int(input())
    the_two_tower_heights = list(map(int, input().split()))

    bottom_tower = [0] * n

    for i in range(n):
        # First element
        if i == 0:
            if n == 1:
                bottom_tower[i] = the_two_tower_heights[i]
            else:
                bottom_tower[i] = min(the_two_tower_heights[i], the_two_tower_heights[i + 1])

        # Last element
        elif i == n - 1:
            bottom_tower[i] = min(the_two_tower_heights[i], the_two_tower_heights[i - 1])

        # Middle elements
        else:
            left = the_two_tower_heights[i - 1]
            current = the_two_tower_heights[i]
            right = the_two_tower_heights[i + 1]

            # Find median of three values
            values = [left, current, right]
            values.sort()
            bottom_tower[i] = values[1]

    print(*bottom_tower)


def read_your_input():
    return map(int, input().split())