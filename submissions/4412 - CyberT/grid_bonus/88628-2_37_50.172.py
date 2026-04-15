import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = a[:]   
    for i in range(1, n):
        if b[i] < b[i-1]:
            b[i] = b[i-1]
    for i in range(n-2, -1, -1):
        if b[i] > b[i+1]:
            b[i] = b[i+1]
    print(*b)
def read_your_input():
    pass