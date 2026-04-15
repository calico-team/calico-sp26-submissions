
t = int(input())

for _ in range(t):
    n, poder, salud, k = map(int, input().split())
    e = list(map(int, input().split()))
    
    usados = 0
    gana = True
    
    for x in e:
        poder -= x
        usados += 1
        
        if poder < 0:
            gana = False
            break
        
        if usados == k:
            poder += salud
            usados = 0
    
    if gana:
        print("nah i'd win")
    else:
        print("nah i'd lose")