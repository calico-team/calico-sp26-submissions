def make_the_criss_cross(total_rows, total_cols):
    quilt_design = []
    for current_row in range(total_rows):
        single_row = []
        for current_col in range(total_cols):
            stitch_value = (2 * current_row + current_col) % 5
            single_row.append(stitch_value)
        quilt_design.append(single_row)
    return quilt_design

T = int(input())

for _ in range(T):
    total_rows, total_cols = map(int, input().split())

    grandma_quilt = make_the_criss_cross(total_rows, total_cols)

    for each_row in grandma_quilt:
        print(*each_row)

def read_your_input():
    return map(int, input().split())