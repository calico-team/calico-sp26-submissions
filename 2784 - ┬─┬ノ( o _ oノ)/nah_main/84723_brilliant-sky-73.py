t = int(input())
for i in range(t):
    n, p, r, k = map(int, input().split())
    curses = list(map(int, input().split()))
    
    b = 0
    beat = True
    for c in curses:
        if b >= k:
            p += r
        p -= c
        if p < 0:
            print("nah i'd lose")
            beat = False
            break 
        b += 1
        
    if beat:
        print("nah i'd win")