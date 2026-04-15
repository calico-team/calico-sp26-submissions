tests = int(input())
for i in range(tests):
    rows, columns = map(int, input().split())
    for row in range(rows):
        line = []
        for column in range(columns):
            line.append(str((row + 2 * column) % 5))
        print(" ".join(line))