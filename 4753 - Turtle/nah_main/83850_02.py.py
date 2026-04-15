def solve():
    g = int(input(":"))

    for i in range(g):
        n, p, r, k = map(int, input().split())
        E = list(map(int, input().split()))

        power = p

        for i, val in enumerate(E, 1):
            power -= val

            if power < 0:
                print("nah i’d lose")
                break

            if i % k == 0:
                power += r
        else:
            print("nah i’d win")
solve()
