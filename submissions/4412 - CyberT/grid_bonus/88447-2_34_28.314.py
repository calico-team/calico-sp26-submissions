import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    number = int(input())
    arr = list(map(int, input().split()))
    ans = []
    for x in arr:
        ans.append(x)
    print(*ans)
def read_your_input():
    pass