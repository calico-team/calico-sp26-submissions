def solve(P, A, B):
    """
    Build a factory with N rows and M columns that produces the target rate.
    
    P: the target numerator of the fraction P / (2^A * 3^B)
    A: the exponent of 2 in the denominator
    B: the exponent of 3 in the denominator
    """
    split_sizes = [2] * A + [3] * B
    total_denominator = (2**A) + (3**B)

    keep_counts = []
    remain_num = P

    for split_size in split_sizes:
        total_denominator //= split_size
        keep_here = remain_num // total_denominator
        keep_counts.append(keep_here)
        remain_num %= total_denominator

    steps = len(split_sizes)
    width = 2 * steps + 1
    grid = [['.' for _ in range(width)] for _ in range(4)]

    grid[0][0] = "v"
    grid[1][0] = ">"

    for step_index in range(steps):
        split_col = 1 + 2 * step_index
        split_size = split_sizes[step_index]
        keep_here = keep_counts[step_index]
        is_last = (step_index == steps - 1)

    grid[1][split_col] = 'S'
    
    if is_last:
        grid[1][split_col + 1] = "X"
    else:
        grid[1][split_col + 1] = ">"

    if split_size == 2:
        if keep_here == 1:
            grid[0][split_col] = "^"
        else:
            grid[0][split_col] = "X"
    else:
        if keep_here == 0:
            grid[0][split_col] = "X"
            grid[2][split_col] = "X"
        elif keep_here == 1:
            grid[0][split_col] = "^"
            grid[2][split_col] = "X"
        else:
            grid[0][split_col]= "^"
            grid[0][split_col]= "v"
            grid[0][split_col]= "v"


    return [''.join(row) for row in grid]


def main():
    test_count = int(input())
    for _ in range(test_count):
        P, A, B = map(int, input().split())
        factory = solve(P, A, B)
        row_count = len(factory)
        col_count = len(factory[0])
        print(row_count, col_count)
        for row in factory:
            print(row)



if __name__ == '__main__':
    main()
