t = int(input())

for i in range(t):
    n, p, r, k = map(int, input().split())
    curses = list(map(int, input().split()))
    count = 0
    for c in curses:
        p -= c
        count += 1
        if count == k:
            p += r
            count = 0
        if p < 0:
            print("nah i'd lose")
            break
    
    if p > 0:
        print("nah i'd win")