import math

def calculate_electricity(length: int, width: int, electricity: int, generated: int):
    perimeter = (length + width) * 2
    each_lap = perimeter * generated
    return math.floor(electricity / each_lap)

# Test cases using user input
if __name__ == "__main__":
    length = int(input())
    width = int(input())
    electricity = int(input())
    generated = int(input())

    result = calculate_electricity(length, width, electricity, generated)
    print(result)