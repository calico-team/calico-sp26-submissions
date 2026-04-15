import sys
def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    T_cases = int(input_data[0])
    idx = 1
    dist = abs(xg - xm) + abs(yg - ym)
    low = 0
    high = 10**10
    ans = high
    while low <= high:
        mid = (low + high) // 2
        rg = mid // 2
        rm = mid // 7
        if rg + rm >= dist:
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    print(ans)
solve()


            
    
