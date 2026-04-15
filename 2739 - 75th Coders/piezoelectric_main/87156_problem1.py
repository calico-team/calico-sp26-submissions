# Lets solve the problem

def main():
    with open("datainput.txt", "r") as f:
        data = f.read().strip().split()

    indx1 = 0
    Temp = int(data[indx1])
    indx1 += 1

    results = []

    for _ in range(Temp):
        L = int(data[indx1]); indx1 += 1
        W = int(data[indx1]); indx1 += 1
        E = int(data[indx1]); indx1 += 1
        R = int(data[indx1]); indx1 += 1

        perimeter_formula = 2 * (L + W)
        electricity_per_lap = perimeter_formula * R
        laps_final = E // electricity_per_lap

        results.append(str(laps_final))

    print("\n".join(results))

if __name__ == "__main__":
    main()