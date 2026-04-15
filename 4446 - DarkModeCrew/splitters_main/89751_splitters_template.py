import sys
from fractions import Fraction
def solve(N, M,karkhana):
    hisaab_kitab={}
    
    def safar_karo(qatar,column):
        if qatar<0 or qatar>= N or column <0 or column >= M:
            return Fraction(1,1)
        if (qatar,column) in hisaab_kitab:
            return hisaab_kitab[(qatar,column)]
        
        nishaan= karkhana[qatar][column]
        jawab = Fraction(0, 1)
        
        if nishaan=='X':
            jawab=Fraction(0,1)
        elif nishaan in '^v<>':
            naya_qatar, naya_column=qatar, column
            if nishaan == '^': naya_qatar-=1
            elif nishaan=='v': naya_qatar += 1
            elif nishaan =='<': naya_column -=1
            elif nishaan== '>': naya_column+= 1
            jawab = safar_karo(naya_qatar,naya_column)
        elif nishaan == 'S':
            sahi_raste=[]
            simtein= [(-1,0,'v'), (1, 0, '^'),(0, -1,'>'), (0,1, '<')]
            for dr,dc, wapsi in simtein:
                nq= qatar+dr
                nc =column+ dc
                if 0<= nq <N and 0<=nc< M:
                    agla_nishaan= karkhana[nq][nc]
                    if agla_nishaan == 'X' or (agla_nishaan in '^v<>' and agla_nishaan!=wapsi):
                        sahi_raste.append((nq,nc))
            
            if sahi_raste:
                kul_hissa=sum(safar_karo(nq,nc) for nq,nc in sahi_raste)
                jawab= kul_hissa*Fraction(1,len(sahi_raste))
                
        hisaab_kitab[(qatar, column)]=jawab
        return jawab
        
    aakhri_jawab = safar_karo(0,0)
    return (aakhri_jawab.numerator,aakhri_jawab.denominator)

def main():
    input_data= sys.stdin.read().split()
    if not input_data:
        return
    T =int(input_data[0])
    idx= 1
    for _ in range(T):
        N = int(input_data[idx])
        M=int(input_data[idx+1])
        idx+= 2
        karkhana = []
        for _ in range(N):
            karkhana.append(input_data[idx])
            idx +=1
        P,Q = solve(N,M, karkhana)
        print(f"{P} {Q}")

if __name__ == '__main__':
    main()
    