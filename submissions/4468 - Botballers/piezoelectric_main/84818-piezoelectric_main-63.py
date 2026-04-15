def get_lap_amt():
    try:
        L = int(input("What is the length of the car in meters: "))
        W = int(input("What is the width of the car in meters: "))
        E = int(input("How much electricity does Big Ben need to generate: "))
        R = int(input("How much electricity does Big Ben generate per step: "))

        perimeter = (2 * L) + (2 * W)
        electricity_amt = perimeter * R

        if electricity_amt == 0:
            print("Error: electricity per lap cannot be zero.")
            return

        lap_amt = E / electricity_amt
        print(round(lap_amt))

    except ValueError:
        print("Error: please enter whole numbers only.")

get_lap_amt()
