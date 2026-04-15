# -*- coding: utf-8 -*-
import sys

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    # The first token is the number of test cases
    t = int(input_data[0])
    index = 1

    for i in range(t):
        l = int(input_data[index])
        w = int(input_data[index+1])
        e = int(input_data[index+2])
        r = int(input_data[index+3])
        index += 4

        # Calculate perimeter (2 * (L + W)) and find max laps
        perimeter = 2 * (l + w)
        cost_per_lap = perimeter * r

        print(e // cost_per_lap)

if __name__ == "__main__":
    main()