t = int(input())
for i in range(t):
    cur = 0
    a = input()
    b = input()
    for ch in a:
        if ch == b[cur]:
            print(ch,end='')
            cur += 1
            if cur == len(b):
                break
        else:
            print('#',end='')
    print()