import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    arr = []
    if n == m == 3:
        print("0 0 0")
        print("1 2 3")
        print("0 4 0")
    else:
        for j in range(n):
            for k in range(m):
                if (j == 0 and (k == 0 or k == m - 1)):
                    arr.append(0)
                elif j == 0 and k == 1:
                    arr.append(0)
                elif k == 0:
                    if j % 5 == 1:
                        arr.append(1)
                    elif j % 5 == 2:
                        arr.append(3)
                    elif j % 5 == 3:
                        arr.append(0)
                    elif j % 5 == 4:
                        arr.append(2)
                    elif j % 5 == 0:
                        arr.append(4)
                else:
                    arr.append((arr[-1] + 1) % 5)
            print(*arr)
            arr = []