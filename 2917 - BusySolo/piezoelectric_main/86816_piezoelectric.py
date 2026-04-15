def solve(L, W, E, R):
    perimeter = 2 * (L + W)
    energy_per_step = perimeter * R
    steps = E // energy_per_step
    return steps

def main():
    T = int(input())
    for _ in range(T):
        temp = input().split()
        L = int(temp[0])
        W = int(temp[1])
        E = int(temp[2])
        R = int(temp[3])

        print(solve(L, W, E, R))


if __name__ == "__main__":
    main()