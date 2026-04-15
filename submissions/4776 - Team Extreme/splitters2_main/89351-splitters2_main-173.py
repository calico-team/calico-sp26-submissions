from fractions import Fraction

def solve(P, A, B):
    """
    Build a factory with N rows and M columns that produces the target rate.
    
    P: the target numerator of the fraction P / (2^A * 3^B)
    A: the exponent of 2 in the denominator
    B: the exponent of 3 in the denominator
    """
    goal = Fraction(P, (2**A) * (3**B))

    r0 = ['.']
    r1 = ['>']
    r2 = ['.']

    gc = Fraction(0)
    gf = Fraction(1)

    for _ in range(B):
        un = gf / 3
        rn = goal - gc
        k = min(1, int(rn / un))
        r0.append('^' if k == 1 else 'X')
        r1.append('S')
        r2.append('X')
        r0.append('.')
        r1.append('>')
        r2.append('.')
        gc += k * un
        gf = un

    for _ in range(A):
        un = gf / 2
        rn = goal - gc
        k = min(1, int(rn / un))
        r0.append('.')
        r1.append('S')
        r2.append('X')
        r0.append('.')
        r1.append('>')
        r2.append('.')
        gc += k * un
        gf = un

    if gc + gf != goal:
        r1[-1] = 'X'

    return [''.join(r0), ''.join(r1), ''.join(r2)]


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