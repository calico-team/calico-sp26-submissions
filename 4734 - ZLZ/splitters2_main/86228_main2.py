def solve():
    T = int(input())
    for _ in range(T):
        P, A, B = map(int, input().split())

        total_leaves = (2 ** A) * (3 ** B)
        height = A + B + 3
        width = total_leaves + 2

        grid = [['.' for _ in range(width)] for _ in range(height)]

        row = 0
        current_x = 1

        for level in range(A):
            num_splitters = 2 ** level
            splitter_spacing = width // (num_splitters + 1)

            for i in range(num_splitters):
                x = (i + 1) * splitter_spacing
                grid[row][x] = 'S'
                if level > 0:
                    pass

        for i in range(P):
            grid[0][i] = '^'

        destroy_x = width - 1
        grid[height - 1][destroy_x] = 'X'


        print(height, width)
        for row in grid:
            print(''.join(row))


if __name__ == "__main__":
    solve()