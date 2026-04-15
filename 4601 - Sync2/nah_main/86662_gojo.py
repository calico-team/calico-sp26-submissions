a = int(input())

for _ in range(a):
    n, p, r, k = map(int, input().split())
    arr = list(map(int, input().split()))

    power = p
    i = 0

    while i < n:
        power = power - arr[i]

        if power < 0:
            print("nah i’d lose")
            break

        if (i + 1) % k == 0:
            power = power + r

        i += 1

    else:
        print("nah i’d win")