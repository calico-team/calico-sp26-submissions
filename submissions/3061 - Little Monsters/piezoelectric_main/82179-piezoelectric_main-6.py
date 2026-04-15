def solve():
    length, width, energy, perstep = map(int, input().split())
    return int(energy / (2 * (length + width) * perstep))

for _ in range(int(input())):
    print(solve())