tc = int(input())
for _ in range(tc):
    n, p, r, k = map(int, input().split())
    nl = list(map(int, input().split()))
    
    rusage = False
    poss = True
    
    for i in range(n):
        if p < nl[i]:
              if not rusage or p + r < nl[i]:
                   poss = False
                   break
              p += r
              rusage = False
        p -= nl[i]
        
        if p < 0:
            poss = False
            break
        
        if (i+1) % k == 0:
            rusage = True
    
    print("nah i'd win" if poss else "nah i'd lose")