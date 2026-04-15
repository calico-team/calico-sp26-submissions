T = int(input("number of test cases"))
for i in range(T):
        L, W, E, R = input("length and width of the car, amount of electricity needed and amount of electricity generated per step?").split()
        L, W, E, R = int(L), int(W), int(E), int(R)
        P = (2*L)+(2*W)
        laps = int(E/(P*R))
        print(laps) 
