T = int(input())
for h in range(T):
    A = input().strip()
    B = input().strip()
    pool = list(B)
    result = ""
    for i in B:
        if i in pool:
            result += i
            pool.remove(i)
        else:
            result += "#"
    print(result)