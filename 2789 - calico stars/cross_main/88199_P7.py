def solve(N, M):
    def cc(r, c):
        s = r % 3
        if s == 0:
            return 0
        elif s == 1:
            return (c % 3) + 1
        else:
            return 4

    grid = [[cc(r, c) for c in range(M)] for r in range(N)]
    return grid


def main():
    T = int(input())
    for i in range(T):
        temp = input().split()
        N = int(temp[0])
        M = int(temp[1])
        grid = solve(N, M)
        for row in grid:
            print(' '.join(str(x) for x in row))


if __name__ == '__main__':
    main()