t = int(input())
for i in range(t):

    cur = 0
    a = input()
    b = input()
    for ch in a:
        if cur==len(b):
            print('#',end='')
            continue
        if ch == b[cur]:
            print(ch,end='')
            cur += 1
        else:
            print('#',end='')
    print()
