import math

def calculate_laps(L, W, E, R):
    P = 2 * (L + W)
    E_l = P * R
    laps = E / E_l
    return math.ceil(laps)

case_1 = calculate_laps(5, 3, 128, 2)
case_2 = calculate_laps(10, 5, 300, 10)
case_3 = calculate_laps(2, 2, 400, 5)

print(f"Case 1: {case_1}")
print(f"Case 2: {case_2}")
print(f"Case 3: {case_3}")