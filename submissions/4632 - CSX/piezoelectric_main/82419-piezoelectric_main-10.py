t = int(input())
for i in range(t):
    tmp = list(map(int, input().split(' ')))
    l, w, e, r = tmp[0], tmp[1], tmp[2], tmp[3]
    c = 2 * (l + w)
    print(e // (c * r))
