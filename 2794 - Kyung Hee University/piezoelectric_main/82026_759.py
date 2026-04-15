import sys
input = sys.stdin.readline

for i in range(int(input())):
    l, w, e, r = map(int, input().split())
    print(e // ((l + w) * 2 * r))
