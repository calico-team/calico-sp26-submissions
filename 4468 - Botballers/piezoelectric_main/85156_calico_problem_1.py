def get_lap_amt():
    L, W, E, R = map(int, input().split())
    perimeter = (2 * L) + (2 * W)
    electricity_amt = perimeter * R
    if electricity_amt == 0:
        print(0)
        return
    lap_amt = E / electricity_amt
    print(round(lap_amt))

get_lap_amt()
