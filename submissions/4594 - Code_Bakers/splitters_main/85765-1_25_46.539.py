def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    # YOUR CODE HERE
    
    
    from fractions import Fraction

    dirs = {
        '^': (-1, 0),
        'v': (1, 0),
        '<': (0, -1),
        '>': (0, 1)
    }

    def valid(i, j):
        return 0 <= i < N and 0 <= j < M

    f = [[Fraction(0, 1) for _ in range(M)] for _ in range(N)]

    # boundary condition: outside = 1
    def get(i, j):
        if not valid(i, j):
            return Fraction(1, 1)
        return f[i][j]

    
    for _ in range(100):
        new = [[Fraction(0, 1) for _ in range(M)] for _ in range(N)]

        for i in range(N):
            for j in range(M):
                cell = factory[i][j]

                if cell == 'X':
                    new[i][j] = Fraction(0, 1)

                elif cell in dirs:
                    di, dj = dirs[cell]
                    ni, nj = i + di, j + dj
                    new[i][j] = get(ni, nj)

                elif cell == 'S':
                    total = Fraction(0, 1)
                    cnt = 0

                    for di, dj in dirs.values():
                        ni, nj = i + di, j + dj
                        if valid(ni, nj) and factory[ni][nj] != '.':
                            total += get(ni, nj)
                            cnt += 1

                    if cnt > 0:
                        new[i][j] = total / cnt

        f = new

    ans = f[0][0]
    return ans.numerator, ans.denominator


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    main()
