def make_the_criss_cross(n, m):
    grid = []
    for i in range(n):
        row = []
        for j in range(m):
            val = (2 * i + j) % 5
            row.append(val)
        grid.append(row)
    return grid
def solve(n, m):
    return make_the_criss_cross(n, m)
def main():
    t_str = input()
    if not t_str:
        return
    t = int(t_str)
    for _ in range(t):
        temp = input().split()
        n = int(temp[0])
        m = int(temp[1])
        grid = solve(n, m)
        for row in grid:
            print(' '.join(str(x) for x in row))

if __name__ == '__main__':
    main()
