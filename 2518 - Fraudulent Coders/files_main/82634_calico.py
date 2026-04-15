import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    a = input().strip()
    b = input().strip()
    new = []
    j = 0
    for i in range(len(b)):
        while j < len(a):
            if a[j] == b[i]:
                new.append(b[i])
                j += 1
                break
            else:
                new.append("#")
                j += 1
    while j < len(a):
        new.append("#")
        j += 1
    print("".join(new))