import sys
# sys.stdin = open("1.in")
input = sys.stdin.readline

tcs = int(input())

for tc in range(tcs):
    l, w, e, r = map(int, input().split())
    perimeter = 2 * (l + w)
    energy_per_lap = perimeter * r
    print(e // energy_per_lap)
