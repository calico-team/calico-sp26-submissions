import sys
input = sys.stdin.readline




t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    def solve(tup):
        li = tup[1]
        if n == 2:
            t1, t2, b1, b2 = arr[0], arr[1], li[0], li[1]
            return (abs(t1 - t2) + abs(b1 - b2) + abs(t1 - b1) + abs(t2 - b2))

        t1, t2, t3 = arr[0], arr[1], arr[2]
        b1, b2, b3 = li[0], li[1], li[2]
        return (
            abs(t1 - b1) + abs(t2 - b2) + abs(t3 - b3) +
            abs(t2 - t1) + abs(t3 - t2) + 
            abs(b2 - b1) + abs(b3 - b2)
        )


    if n == 1:
        print(arr[0])
    
    if n == 2:
        cans = [[arr[0], arr[0]], [arr[1], arr[1]], [arr[0], arr[1]]]
    
    if n == 3:
        cans = [
            [arr[0], arr[0], arr[0]],
            [arr[1], arr[1], arr[1]],
            [arr[2], arr[2], arr[2]],
            [arr[0], arr[1], arr[2]]]

    index, min_val = min(enumerate(cans), key=solve)
    print(*cans[index])

    # a = [arr[0]]
    # for j in range(1, n - 1):
    #     if abs(arr[j + 1] - a[j - 1]) < abs(arr[j + 1] - arr[j]):
    #         a.append(a[j - 1])
    #     else:
    #         a.append(arr[j])
    # a.append(arr[-1])
    # print(*a)