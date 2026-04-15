test = int(input())
for _ in range(test):
    length, width, electricity, run = map(int, input().split())
    perfect = 2 * (length + width)
    print(electricity // (perfect * run))