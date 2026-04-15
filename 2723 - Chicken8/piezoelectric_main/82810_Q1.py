import math

def calculate_electricity(length: int, width: int, electricity: int, generated: int):
    perimeter = (length + width) * 2
    each_lap = perimeter * generated
    return electricity // each_lap


if __name__ == "__main__":
    test_cases = int(input())
    for _ in range(test_cases):
        length, width, electricity, generated = map(int, input().split())
        print(calculate_electricity(length, width, electricity, generated))