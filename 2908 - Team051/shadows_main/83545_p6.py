T = int(input())

for i in range(T):
    N = int(input())
    
    s1 = []
    for i in range(N):
        s1.append(input())

    s2 = []
    for i in range(N):
        s2.append(input())
        
    vol_maximo = 0
    vol_minimo = 0

    for j in range(N):

        bloques_s1 = 0
        for char in s1[j]:
            if char == '#':
                bloques_s1 += 1
                
        bloques_s2 = 0
        for char in s2[j]:
            if char == '#':
                bloques_s2 += 1
        
        vol_maximo += bloques_s1 * bloques_s2
        
        if bloques_s1 > bloques_s2:
            vol_minimo += bloques_s1
        else:
            vol_minimo += bloques_s2
            
    print(f"{vol_maximo} {vol_minimo}")