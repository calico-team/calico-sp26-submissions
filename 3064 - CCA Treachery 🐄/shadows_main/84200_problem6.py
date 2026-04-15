tests = int(input())
for _ in range(tests):
    length = int(input())
    rows_1 = []
    rows_2 = []
    for i in range(length):
        val = input().strip()
        rows_1.append(val.count('#'))
    for i in range(length):
        val = input().strip()
        rows_2.append(val.count('#'))
    product = 0
    sum = 0
    for i in range(length):
        product += rows_1[i] * rows_2[i]
        sum += max(rows_1[i],rows_2[i])
    print(product, sum)