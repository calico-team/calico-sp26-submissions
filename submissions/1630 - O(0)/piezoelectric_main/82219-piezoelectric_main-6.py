t = int(input())
for _ in range(t):
    l, w, e, r = map(int, input().split())
    p = 2*(l+w)
    print(e // (p*r))