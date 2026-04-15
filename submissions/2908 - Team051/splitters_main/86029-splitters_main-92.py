import sys
from fractions import Fraction

def resolver():
    entrada = sys.stdin.readline().split()
    N, M = map(int, entrada)
    
    fabrica = [sys.stdin.readline().strip() for i in range(N)]
    memoria = {}

    def camino(f, c):
        if f < 0 or f >= N or c < 0 or c >= M: 
            return Fraction(1, 1)
        
        if (f, c) in memoria: 
            return memoria[(f, c)]
        
        simbolo = fabrica[f][c]
        
        if simbolo in '.X': 
            return Fraction(0, 1)
        
        if simbolo == '^': resultado = camino(f - 1, c)
        elif simbolo == 'v': resultado = camino(f + 1, c)
        elif simbolo == '<': resultado = camino(f, c - 1)
        elif simbolo == '>': resultado = camino(f, c + 1)
        else:
            opciones = []
            direcciones = [(-1, 0, 'v'), (1, 0, '^'), (0, -1, '>'), (0, 1, '<')]
            for i in range(4):
                df, dc, contra = direcciones[i]
                nf, nc = f + df, c + dc
                if nf < 0 or nf >= N or nc < 0 or nc >= M:
                    opciones.append(camino(nf, nc))
                else:
                    vecino = fabrica[nf][nc]
                    if vecino == 'X' or (vecino in '^v<>' and vecino != contra):
                        opciones.append(camino(nf, nc))
            
            resultado = sum(opciones) / len(opciones) if opciones else Fraction(0, 1)
            
        memoria[(f, c)] = resultado
        return resultado

    final = camino(0, 0)
    print(f"{final.numerator} {final.denominator}")

linea_T = sys.stdin.readline().strip()
if linea_T:
    T = int(linea_T)
    for i in range(T):
        resolver()