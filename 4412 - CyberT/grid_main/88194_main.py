import sys
input = sys.stdin.readline
cases = int(input())
for _ in range(cases):
    n = int(input())
    a = list(map(int, input().split()))
    b = sorted(a)
    mid = b[n//2]  
    ans = []
    for i in range(n):
        ans.append(mid)
    print(*ans)
def read_your_input():
    pass