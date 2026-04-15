T = int(input())
for i in range(T):
    l, w, e, r = map(int, input().split())
    steps = e // r
    perimeter = 2 * l + 2 * w
    print(steps // perimeter)