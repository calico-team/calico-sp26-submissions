T = int(input())

for _ in range(T):
    n = int(input())

    shadow_front = []
    for _ in range(n):
        shadow_front.append(input().strip())

    shadow_side = []
    for _ in range(n):
        shadow_side.append(input().strip())

    max_volume = 0
    min_volume = 0

    # Process each height (layer)
    for layer in range(n):
        front_blocks = shadow_front[layer].count('#')
        side_blocks = shadow_side[layer].count('#')

        # Maximum possible cubes at this layer
        max_volume += front_blocks * side_blocks

        # Minimum cubes needed to satisfy both shadows
        min_volume += max(front_blocks, side_blocks)

    print(max_volume, min_volume)


def read_your_input():
    return map(int, input().split())