import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    a = [arr[0]]
    for j in range(1, n - 1):
        if abs(arr[j + 1] - a[j - 1]) < abs(arr[j + 1] - arr[j]):
            a.append(a[j - 1])
        else:
            a.append(arr[j])
    a.append(arr[-1])
    print(*a)