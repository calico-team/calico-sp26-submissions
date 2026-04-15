T = int(input())
for i in range(T):
    n, p, r, k = map(int, input().split())
    curses = list(map(int, input().split()))
    curses_sum = 0
    for i in range(len(curses)):
        curses_sum += curses[i]
    if curses_sum > p + r * (n // k):
        print("nah i'd lose")
    else:
        print("nah i'd win")