T = int(input())
for _ in range(T):
    N = int(input())
    numbers = list(map(int, input().split()))
    mylist = []
    mylist.append(numbers[0])
    for i in range(1, N - 1):
        b = numbers[i - 1]
        c = numbers[i]
        d = numbers[i + 1]
        minbc = min(b, c)
        maxbc = max(b, c)
        if d <= minbc:
            mylist.append(minbc)
            continue
        elif d >= maxbc:
            mylist.append(maxbc)
            continue
        else:
            mylist.append(d)
    mylist.append(numbers[N-1])
    print(" ".join(map(str, mylist)))