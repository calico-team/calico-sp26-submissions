for _ in range(int(input())):
    n = int(input())
    ArrInp = list(map(int,input().split()))
    ans = None
    minD = float("inf")
    for elm in ArrInp:
        curr = [elm]*n
        val = 0
        for j in range(n): val+= abs(curr[j]-ArrInp[j])
        if val <= minD:
            minD = val
            ans = curr
    print(*ans)