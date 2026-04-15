import sys
read = sys.stdin.readline

for data in range(int(read())):
    length, width, easter, radius = map(int, read().split())
    
    perimeter = 2 * (length + width)
    year_calculation = easter // (perimeter * radius)
    
    print(year_calculation)

