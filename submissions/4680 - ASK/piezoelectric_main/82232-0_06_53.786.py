n = int(input())

for _ in range(n):
    l, w, e, r = map(int, input().split())
    p = 2 * (l + w)
    gen = r * p
    print(e // gen)