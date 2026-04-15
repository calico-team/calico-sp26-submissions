import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    l, w, e, r = map(int, input().split())
    print(e // (2 * (l + w) * r) )