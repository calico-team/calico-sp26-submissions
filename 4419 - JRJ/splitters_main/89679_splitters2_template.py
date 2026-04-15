def solve(P, A, B):
    """
    Build a factory with N rows and M columns that produces the target rate.
    
    P: the target numerator of the fraction P / (2^A * 3^B)
    A: the exponent of 2 in the denominator
    B: the exponent of 3 in the denominator
    """
     grid = []
    row = []
    row.append('>')
    for _ in range(A):
        row.append('S')
    for _ in range(B):
        row.append('S')
    row.append('>' if P != 0 else 'X')
    grid.append(''.join(row))
    grid.append('.' * len(row))
    return grid

    return ['.']


def main():
    T = int(input())
    for _ in range(T):
        P, A, B = map(int, input().split())
        factory = solve(P, A, B)
        N = len(factory)
        M = len(factory[0])
        print(N, M)
        for row in factory:
            print(row)


if __name__ == '__main__':
    main()
