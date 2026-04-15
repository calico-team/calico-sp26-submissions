def get_lap_amt():
    L = int(input("What is the length of the car in meters: "))
    W = int(input("What is the width of the car in meters: "))
    E = int(input("How much electricity does Big Ben need to generate: "))
    R = int(input("How much electricty does Big Ben generate per step: "))
    perimeter = (2*L) + (2*W)
    print(perimeter)
    electricty_amt = perimeter * R
    lap_amt = E/electricty_amt
    print(round(lap_amt))
get_lap_amt()
    
