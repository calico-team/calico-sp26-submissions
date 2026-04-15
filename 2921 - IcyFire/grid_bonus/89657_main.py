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

    vertical = 0
    for x in a:
        vertical = vertical + abs(x - m)
    cost2 = top_cost + vertical

    b3 = [0] * n
    b3[0] = a[0]
    for i in range(1, n):
        b3[i] = int((a[i] + b3[i - 1]) // 2)
    cost3 = 0
    for i in range(n - 1):
        cost3 = cost3 + abs(b3[i] - b3[i + 1])
    for i in range(n):
        cost3 = cost3 + abs(a[i] - b3[i])
    cost3 = cost3 + top_cost

    if cost1 <= cost2 and cost1 <= cost3:
        print(*a)
    elif cost2 <= cost3:
        b = []
        for i in range(n):
            b.append(m)
        print(*b)
    else:
        print(*b3)