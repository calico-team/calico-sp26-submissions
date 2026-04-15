import sys
input = sys.stdin.readline
tt = int(input())
for _ in range(tt):
    number = int(input())
    helper = list(map(int, input().split()))
    b = helper[:]
    b.sort()
    val = b[number//2]
    ans = [0]*number
    for i in range(number):
        ans[i] = val
    print(*ans)
def read_your_input():
    pass