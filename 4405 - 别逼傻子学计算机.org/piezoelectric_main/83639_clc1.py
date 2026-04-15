n = int(input())
for i in range (n) :
    l, w, e, r = map(int, input().split())
    c = l * 2 + w * 2
    step = e // r
    res = step // c
    print(res)

