cases = int(input())
final = []

for x in range(cases):
    rows, cols = map(int, input().split())

    start = 0

    for r in range(rows):
        currentRow = []
        number = start

        for c in range(cols):
            currentRow.append(str(number))
            number += 1

            if number == 5:
                number = 0

        final.append(" ".join(currentRow))

        start += 2
        if start >= 5:
            start -= 5

for y in final:
    print(y)