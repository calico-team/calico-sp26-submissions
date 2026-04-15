def solve(target_num, power_two, power_three):
    split_sizes = [2] * power_two + [3] * power_three
    total_denominator = (2 ** power_two) * (3 ** power_three)

    keep_amounts = []
    remaining_numerator = target_num
    remaining_denominator = total_denominator

    for current_split in split_sizes:
        next_denominator = remaining_denominator // current_split
        keep_amount = remaining_numerator // next_denominator
        keep_amounts.append(keep_amount)
        remaining_numerator %= next_denominator
        remaining_denominator = next_denominator

    step_total = len(split_sizes)
    grid_width = 2 * step_total + 1
    factory_grid = [['.' for _ in range(grid_width)] for _ in range(4)]

    factory_grid[0][0] = 'v'
    factory_grid[1][0] = '>'

    for step_index in range(step_total):
        splitter_col = 1 + 2 * step_index
        current_split = split_sizes[step_index]
        keep_amount = keep_amounts[step_index]
        is_last_step = step_index == step_total - 1

        factory_grid[1][splitter_col] = 'S'

        if is_last_step:
            factory_grid[1][splitter_col + 1] = 'X'
        else:
            factory_grid[1][splitter_col + 1] = '>'

        if current_split == 2:
            if keep_amount == 1:
                factory_grid[0][splitter_col] = '^'
            else:
                factory_grid[0][splitter_col] = 'X'
        else:
            if keep_amount == 0:
                factory_grid[0][splitter_col] = 'X'
                factory_grid[2][splitter_col] = 'X'
            elif keep_amount == 1:
                factory_grid[0][splitter_col] = '^'
                factory_grid[2][splitter_col] = 'X'
            else:
                factory_grid[0][splitter_col] = '^'
                factory_grid[2][splitter_col] = 'v'
                factory_grid[3][splitter_col] = 'v'

    return [''.join(row) for row in factory_grid]


def main():
    test_count = int(input())
    for _ in range(test_count):
        target_num, power_two, power_three = map(int, input().split())
        factory = solve(target_num, power_two, power_three)
        row_total = len(factory)
        col_total = len(factory[0])
        print(row_total, col_total)
        for row in factory:
            print(row)


if __name__ == '__main__':
    main()