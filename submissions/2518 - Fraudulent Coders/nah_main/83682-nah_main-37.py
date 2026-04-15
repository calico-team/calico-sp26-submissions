import sys
input = sys.stdin.readline

t = int(input())
for i in range(t):
    n, p, r, k = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.reverse()
    kill = 0
    while len(arr) > 0:
        p -= arr.pop()
        kill += 1
        if p < 0:
            print("nah i'd lose")
            break
        else:
            if kill >= k:
                p += r
                kill = 0
    if not p < 0:
        print("nah i'd win")
    