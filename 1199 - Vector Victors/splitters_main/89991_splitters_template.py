from fractions import Fraction
import sys
dirs = {
    "<": (-1, 0),
    ">": (1, 0),
    "^": (0, -1),
    "v": (0, 1)
}

def search(factory, x, y, N, M):
    tile = factory[y][x]
    #print(tile)
    if tile == "X":
        return 0
    elif tile == "S":
        #print('asdfsdf')
        rate = 0  # total amount possible (no division)
        splits = 0
        for dir_ in dirs.values():
            pos = x + dir_[0], y + dir_[1]

            newtile = factory[pos[1]][pos[0]]
            if newtile == "X":
                rate += 0
                splits += 1
            elif newtile == ">" and not dir_ == (-1,0) or \
                    newtile == "^" and not dir_ == (0, 1) or \
                    newtile == "v" and not dir_ == (0, -1) or \
                    newtile == "<" and not dir_ == (1, 0):
                # works ig
                splits += 1
                rate += search(factory, *pos, N, M)
        #print(rate, splits, rate* Fraction(1, splits))
        return Fraction(rate, splits)
    else:  # check next conveyor
        dir_ = dirs.get(tile)
        #print(dir_)
        pos = x + dir_[0], y + dir_[1]
        if pos[0] < 0 or pos[0] > M-1 or pos[1] < 0 or pos[1] > N-1:
            return 1
        return search(factory, *pos, N, M)


def solve(N, M, factory):
    """
    Simulate the factory and return the final output as the fraction P / Q.

    N: number of rows in the factory grid
    M: number of columns in the factory grid
    factory: list of N strings of length M, each character one of '^<>vSX.'
    """
    # YOUR CODE HERE
    rate = search(factory, 0, 0, N, M)
    #print()

    return (rate.numerator, rate.denominator)


def main():
    T = int(input())
    for _ in range(T):
        N, M = map(int, input().split())
        factory = [input() for _ in range(N)]
        P, Q = solve(N, M, factory)
        print(P, Q)


if __name__ == '__main__':
    sys.setrecursionlimit(100000)
    main()
