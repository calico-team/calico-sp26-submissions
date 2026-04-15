import sys
input = sys.stdin.readline

for i in range(int(input())):
    s1 = input().strip()
    s2 = input().strip() + '*'
    idx = 0
    for i in s1:
        if i == s2[idx]:
            print(i,end='')
            idx += 1
        else:
            print('#',end='')
    print()
