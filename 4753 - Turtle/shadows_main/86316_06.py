def solve():
    n = int(input())

    for i in range(n):
        n = int(input())

        s1 = [input().strip() for i in range(n)]
        s2 = [input().strip() for i in range(n)]

        col_s1 = [0] * n
        row_s2 = [0] * n

        for i in range(n):
            for j in range(n):
                if s1[i][j] == '#':
                    col_s1[j] += 1

        for i in range(n):
            for j in range(n):
                if s2[i][j] == '#':
                    row_s2[i] += 1

        min_vol = 0
        max_vol = 0

        for i in range(n):
            min_vol += max(col_s1[i], row_s2[i])
            max_vol += col_s1[i] * row_s2[i]

        print(max_vol, min_vol)

    solve()


if __name__ == "__main__":
    solve()

