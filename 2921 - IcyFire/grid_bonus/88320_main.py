T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))

    top_cost = 0
    for i in range(n - 1):
        top_cost = top_cost + abs(a[i] - a[i + 1])

    cost1 = 2 * top_cost

    sorted_a = sorted(a)
    m = sorted_a[n // 2]

    ver = 0
    for x in a:
        ver = ver + abs(x - m)
    cost2 = top_cost + ver

    if cost1 <= cost2:
        print(*a)
    else:
        b = []
        for i in range(n):
            b.append(m)
        print(*b)