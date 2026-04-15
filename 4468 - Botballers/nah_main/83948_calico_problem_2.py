def solve():
    n, p, r, k = map(int, input().split())
    dylan_power = p
    curses = list(map(int, input().split()))
    
    defeated = 0
    for e in curses:
        dylan_power -= e
        if dylan_power < 0:
            print("nah i'd lose")
            return
        defeated += 1
        if defeated % k == 0:
            dylan_power += r
    
    print("nah i'd win")

t = int(input())
for _ in range(t):
    solve()
