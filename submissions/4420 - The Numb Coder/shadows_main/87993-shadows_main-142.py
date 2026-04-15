import sys

def calculate_volume_extremes(grid_size, front_view, side_view):
    # Tracks the highest and lowest possible block counts
    max_volume = 0
    min_volume = 0

    for level in range(grid_size):
        front_layer = front_view[level]
        side_layer = side_view[level]

        # Simply count the '#' characters instead of building a whole list
        x_blocks = front_layer.count('#')
        y_blocks = side_layer.count('#')

        # Maximum possible volume fills every intersection
        max_volume += (x_blocks * y_blocks)

        # Minimum possible volume just covers the widest shadow
        min_volume += max(x_blocks, y_blocks)

    return max_volume, min_volume

def process_tests():
    # Grab all inputs at once to easily handle weird spacing/line breaks
    raw_input = sys.stdin.read().split()
    if not raw_input:
        return

    tokens = iter(raw_input)

    try:
        total_cases = int(next(tokens))

        for i in range(total_cases):
            dimension = int(next(tokens))

            # Read the grids for both perspectives
            shadow_a = [next(tokens) for _ in range(dimension)]
            shadow_b = [next(tokens) for _ in range(dimension)]

            highest, lowest = calculate_volume_extremes(dimension, shadow_a, shadow_b)
            print(f"{highest} {lowest}")

    except (StopIteration, ValueError):
        # Failsafe for unexpected end of file or bad data
        pass

if __name__ == '__main__':
    process_tests()