def make_the_criss_cross(n, m):
    g = []
    for i in range(n):
        row = []
        for j in range(m):
            val = (2 * i + j) % 5
            row.append(val)
        g.append(row)
    return g
def solve(n, m):
    return make_the_criss_cross(n, m)
def main():
    t_str = input()
    if not t_str:
        return
    t = int(t_str)
    for i in range(t):
        te = input().split()
        n = int(te[0])
        m = int(te[1])
        g = solve(n, m)
        for j in g:
            print(' '.join(str(x) for x in row))

if __name__ == '__main__':
    main()
