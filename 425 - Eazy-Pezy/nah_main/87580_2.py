tc = int(input())
for _ in range(tc):
    n, p, r, k = map(int, input().split())
    nl = list(map(int, input().split()))
    
    kused = 0
    rusage = False
    poss = True
    
    for i in range(n):
        p -= nl[i]
        kused += 1
        
     
        if p < 0:
            if rusage:
                p += r
                rusage = False
            else:
                poss = False
                break
        
        
        if kused % k == 0:
            rusage = True
    
    print("nah i'd win" if poss else "nah i'd lose")