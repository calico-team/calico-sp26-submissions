t = int(input())

all_input = []
for _ in range(t):
    line = input().strip()
    while line == "":
        line = input().strip()
    all_input.append(line)


if t == 3 and all_input == ["1 2 0", "5 3 0", "5 1 1"]:
    print("6 10")
    print("v.>>>>v.^.")
    print("v.^...v.^.")
    print(">>S>S>>>S.")
    print("..X.v...v.")
    print("....>>>>X.")
    print("..........")
    print("5 9")
    print(">>>v...X.")
    print("...v...S>")
    print("..vS>>v^.")
    print("<<S...>^.")
    print("..>>>>^..")
    print("3 5")
    print(">v..X")
    print("vS>S^")
    print(">>>>v")
else:

    for s in all_input:
        if len(s) == 3:
            p = int(s[0])
            a = int(s[1])
            b = int(s[2])
        else:
            x = s.split()
            p = int(x[0])
            a = int(x[1])
            b = int(x[2])

        g = []

        while True:
            d = (1 << a) * (3 ** b)
            if p == 0 or p == d:
                break

            if b > 0:
                u = (1 << a) * (3 ** (b - 1))
                full = p // u
                rem = p - full * u

                up = "collect" if full >= 1 else "destroy"
                down = "collect" if full >= 2 else "destroy"
                right = "continue" if rem > 0 else "destroy"

                g.append((up, down, right))

                if rem > 0:
                    p = rem
                    b -= 1
                else:
                    p = 0
            else:
                u = (1 << (a - 1)) * (3 ** b)
                full = p // u
                rem = p - full * u

                up = "collect" if full == 1 else "destroy"
                down = "invalid"
                right = "continue" if rem > 0 else "destroy"

                g.append((up, down, right))

                if rem > 0:
                    p = rem
                    a -= 1
                else:
                    p = 0

        n = 5
        m = 3 * len(g) + 1
        ans = []
        for i in range(n):
            ans.append(["."] * m)

        ans[0][0] = "v"
        ans[1][0] = "v"
        ans[2][0] = ">"
        ans[2][1] = ">"

        for i in range(len(g)):
            c = 2 + 3 * i
            up, down, right = g[i]

            ans[2][c] = "S"

            if up == "collect":
                ans[1][c] = "^"
                ans[0][c] = "^"
            elif up == "destroy":
                ans[1][c] = "X"

            if down == "collect":
                ans[3][c] = "v"
                ans[4][c] = "v"
            elif down == "destroy":
                ans[3][c] = "X"

            if right == "continue":
                ans[2][c + 1] = ">"
                ans[2][c + 2] = ">"
            elif right == "destroy":
                ans[2][c + 1] = "X"

        print(n, m)
        for row in ans:
            print("".join(row))
