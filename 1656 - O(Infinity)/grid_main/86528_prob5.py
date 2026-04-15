for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    mx = max(arr)
    minDiff = float("inf")
    ans = None
    for i in range(1,mx+1):
        currArr = [i]*n
        SUM = sum(abs(currArr[j]-arr[j]) for j in range(n))
        if SUM<=minDiff:
            minDiff = SUM
            ans = currArr
    print(*ans)