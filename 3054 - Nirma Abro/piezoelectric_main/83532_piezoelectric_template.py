def solve(L, W, E, R):
    """
    Return the number of laps needed to charge the car (rounded up)

    L: Length of car
    W: Width of car
    E: Amount of electricity to generate
    R: Electricity generated per unit distance
    """

    # YOUR CODE HERE
    triangle_area = 2 * (L + W)
    total_energy = 0
    laps = 0
    while total_energy < E:
        steps = triangle_area
        for _ in range(steps):
            total_energy += R
        laps += 1

    return laps


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
