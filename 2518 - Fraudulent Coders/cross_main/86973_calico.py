import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    arr = []
    prev = 0
    if n == m == 3:
        print("0 0 0")
        print("1 2 3")
        print("0 4 0")
    else:
        for j in range(n):
            for k in range(m):
                if (j == 0 and (k == 0 or k == m - 1)) or (j == n - 1 and (k == 0 or k == m - 1)):
                    arr.append(0)
                elif j == 0 and k == 1:
                    arr.append(0)
                elif k == 0 or (j == n - 1 and k == 1):
                    if j == 1 or j == n - 1:
                        arr.append(prev)
                    else:
                        arr.append((prev + 3) % 4)
                elif j == 0 and k == m - 2:
                    arr.append((arr[-1] + 1) % 5)
                    prev = arr[-1]
                else:
                    arr.append((arr[-1] + 1) % 5)
                    if k == m - 1:
                        prev = arr[-1]
            print(*arr)
            arr = []