def elec():
    values = input().split(" ")  # 0 = L, 1 = W, 2 = E, 3 = R
    P = (int(values[1]) * 2) + (int(values[0]) * 2)
    generated = P * int(values[3])
    laps = int(values[2])/generated
    return laps


cases = int(input())
for i in range(cases):
    print(elec())
