import sys
# sys.stdin = open("2.in")
input = sys.stdin.readline

def solve():
    n, p, r, k = map(int, input().split())
    e = list(map(int, input().split()))

    # every k curses, restore r strength
    c = 0
    for curse in e:
        p -= curse
        if p < 0:
            print("nah i'd lose")
            return
        c += 1
        if c == k:
            p += r
            c = 0
    print("nah i'd win")

tcs = int(input())

for tc in range(tcs):
    solve()


