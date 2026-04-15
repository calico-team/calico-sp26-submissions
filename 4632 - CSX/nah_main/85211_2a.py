t = int(input())
ans = []
for _ in range(t):
    n, p, r, k = map(int, input().split())
    curses = list(map(int, input().split()))
    
    alive = True
    defeated_count = 0  # 已击败的诅咒数
    for i in range(n):
        if defeated_count > 0 and defeated_count % k == 0:
            p += r     
        p -= curses[i]
        defeated_count += 1
        if p < 0:
            alive = False
            break
    if alive:
        ans.append("nah i'd win")
    else:
        ans.append("nah i'd lose")

for s in ans:
    print(s)
