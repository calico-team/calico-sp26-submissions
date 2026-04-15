t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    b = [[a[i], i] for i in range(n)]

    ans = [0 for _ in range(n)]

    b.sort()

    if n % 2 != 0:
        med = b[n // 2][0]

        ans = [med for _ in range(n)]

    else:
        med1, med2 = b[n // 2 - 1], b[n // 2]

        for i in range(n):
            if i <= n // 2 - 1:
                ans[b[i][1]] = med1[0]
            else:
                ans[b[i][1]] = med2[0]
                

        
    print(*ans)
