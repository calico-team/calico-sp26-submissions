t = int(input())

for _ in range(t):
    p, a, b = map(int, input().split())

    d = (2 ** a) * (3 ** b)

    if p == 0:
        print(1, 1)
        print("X")
        continue

    if p == d:
        print(1, 1)
        print(">")
        continue

    steps = []

    while a > 0 or b > 0:
        if a > 0:
            child = d // 2
            digit = p // child
            p = p - digit * child
            d = child
            a -= 1
            steps.append((2, digit))
        else:
            child = d // 3
            digit = p // child
            p = p - digit * child
            d = child
            b -= 1
            steps.append((3, digit))

    if p == 1:
        last_tile = ">"
    else:
        last_tile = "X"

    width = 2 * len(steps) + 1

    row1 = ["."] * width
    row2 = ["."] * width
    row3 = ["."] * width

    row2[0] = ">"

    # build the chain
    for i in range(len(steps)):
        kind, digit = steps[i]
        col = 2 * i + 1
        row2[col] = "S"

        if i == len(steps) - 1:
            row2[col + 1] = last_tile
        else:
            row2[col + 1] = ">"

        if kind == 2:
            if digit == 1:
                row1[col] = "^"  
            else:
                row1[col] = "X"

        else:

            if digit >= 1:
                row1[col] = "^"  
            else:
                row1[col] = "X"

            if digit == 2:
                row3[col] = "v"  
            else:
                row3[col] = "X"

    print(3, width)
    print("".join(row1))
    print("".join(row2))
    print("".join(row3))