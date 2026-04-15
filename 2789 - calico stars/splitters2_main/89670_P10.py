from fractions import Fraction

def solve(P, A, B):
    def dtiles():
        return 'X'

    target = Fraction(P, (2**A) * (3**B))

    segments2 = A
    segments3 = B

    r0 = []
    r1 = []
    r2 = []

    r0.append('>')
    r1.append('.')
    r2.append('.')

    cur = Fraction(1)

    for i in range(segments2):
        r0 += list('Sv')
        r1 += list('.>')
        r2 += list('.X')
        cur = cur / 2

    for i in range(segments3):
        r0 += list('Sv')
        r1 += list('vX')
        r2 += list('>>')
        cur = cur * Fraction(2, 3)

    r0.append('^')
    r1.append('.')
    r2.append('.')

    row0 = ''.join(r0)
    row1 = ''.join(r1)
    row2 = ''.join(r2)

    factory = [row0, row1, row2]
    return factory


def main():
    T = int(input())
    for i in range(T):
        P, A, B = map(int, input().split())
        factory = solve(P, A, B)
        N = len(factory)
        M = len(factory[0])
        print(N, M)
        for row in factory:
            print(row)


if __name__ == '__main__':
    main()