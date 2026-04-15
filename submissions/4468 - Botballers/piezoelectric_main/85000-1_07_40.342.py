def get_lap_amt():
    
        L = int(input(" "))
        W = int(input(""))
        E = int(input(" "))
        R = int(input(" "))

        perimeter = (2 * L) + (2 * W)
        electricity_amt = perimeter * R

        if electricity_amt == 0:
            print("")
            return

        lap_amt = E / electricity_amt
        print(round(lap_amt))


get_lap_amt()
