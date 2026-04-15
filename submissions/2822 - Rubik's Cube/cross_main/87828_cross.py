def cross():
    bounds = list(map(int, input().split()))
    phase = 0
    for i in range(bounds[0]):
        temp = ''
        for j in range(bounds[1]):
            temp += str((j + phase) % 5) + ' '
        print(temp)
        phase = (phase + 2) % 5

lines = int(input())
for i in range(lines):
    cross()