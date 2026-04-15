def solve(L, W, E, R):
    """
    Return the number of laps needed to charge the car (rounded up)

    L: Length of car
    W: Width of car
    E: Amount of electricity to generate
    R: Electricity generated per unit distance
    """
    the_distance_of_car = 2 * (L + W)
    energy_required_per_lap = the_distance_of_car * R
    laps_required = (E + energy_required_per_lap - 1) // energy_required_per_lap
    return laps_required

def main():
    T = int(input())
    for _ in range(T):
        temp = input().split()
        L = int(temp[0])
        W = int(temp[1])
        E = int(temp[2])
        R = int(temp[3])

        print(solve(L, W, E, R))

def read_your_input():
    main()

if __name__ == "__main__":
    main()