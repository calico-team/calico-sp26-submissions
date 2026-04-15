T = float(input("enter test cases"))
while T < 1 or T > 10 or T != round(T,0):
    T = input("invalid, enter again")
T = int(T)
for i in range(1,T+1):
    L = float(input("enter length"))
    while L < 1 or L > 100:
        L = input("invalid, enter again")
    W = float(input("enter width"))
    while W < 1 or W > 100:
        W = input("invalid, enter again")
    E = float(input("enter the amount of electricity needed"))
    while E < 1 or E > 10000:
        E = input("invalid, enter again")
    R = float(input("enter the amount of electricity generated per step"))
    while R < 1 or R > 10:
        R = input("invalid, enter again")
    

    results = (E / (R * (2 * (W + L))))
    if results != round(results,0):
        results == int(results+1)
        

    print(f"the laps taken is {results}")