t = int(input())

for _ in range(t):
    l, w, e, r = map(int, input().split())
    permet = 2 * (l + w)
    energylap = permet * r
    print(e // energylap)
