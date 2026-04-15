def solve(N, M):
    grid = []

    i = 0
    while i < N:
        row = []
        j = 0

        if i % 2 == 1:
            val = 1
            while j < M:
                row.append(val)
                val += 1
                if val == 5:
                    val = 0
                j += 1
        else:
            if (i // 2) % 2 == 0:
                while j < M:
                    row.append(0)
                    j += 1
            else:
                while j < M:
                    row.append(4)
                    j += 1

        grid.append(row)
        i += 1

    return grid


def main():
    T = int(input())
    for _ in range(T):
        temp = input().split()
        N = int(temp[0])
        M = int(temp[1])
        grid = solve(N, M)
        for row in grid:
            print(' '.join(str(x) for x in row))


if __name__ == '__main__':
    main()
