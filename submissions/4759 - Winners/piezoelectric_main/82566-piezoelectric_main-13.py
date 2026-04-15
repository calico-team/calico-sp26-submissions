def solve(L, W, E, R):
    import math

    perim = 2 * (L + W)
    return math.ceil(E / (perim * R))


def main():
    T = int(input())
    for _ in range(T):
        temp = input().split()
        L = int(temp[0])
        W = int(temp[1])
        E = int(temp[2])
        R = int(temp[3])

        print(solve(L, W, E, R))


main()
