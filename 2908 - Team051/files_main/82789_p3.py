T = int(input())

for i in range(T):
    A = input()
    B = input()
    
    resultado = []
    indice_b = 0
    limite_b = len(B)
    
    for caracter in A:
       
        if indice_b < limite_b and caracter == B[indice_b]:
            resultado.append(caracter)
            indice_b += 1
        else:
            
            resultado.append('#')
    
    print("".join(resultado))