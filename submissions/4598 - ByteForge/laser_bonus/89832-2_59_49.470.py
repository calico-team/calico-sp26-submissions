import sys 

input= sys.stdin.readline #nnanfkn


def extended_gcd(a, b):
    
    if b == 0:
        
        return a, 1, 0
    g, x , y = extended_gcd (b, a % b)
    
    return g, y, x - (a // b) * y

def solve_crt(r1, m1, r2, m2):
    #ye bi easily hojae ga na 
    
    g, p, q= extended_gcd(m1, m2)
    
    if (r2 - r1)% g !=0:
        return None, None 
    lcm = m1// g*m2
    
    diff= (r2-r1)//g 
    
    t= (r1+m1 * (diff%(m2//g)*p%(m2//g))) % lcm 
    
    return t, lcm 

def find_steps(x0, y0, xi, yi, N, M, P, Q):
    
    dx=(xi-x0)%N
    
    dy=(yi-y0)% M
    
    g1, inv, _ = extended_gcd(Q, N)
    
    if dx % g1 !=0:
        
        return None 
    mod1= N// g1
    
    t1=(dx//g1* inv)%mod1
    
    g2, inv2, __ =extended_gcd(P, M)
    if dy % g2 !=0:
        return None
    mod2=M//g2
    t2=(dy//g2*inv2)%mod2
    
    
    #jaja sahib dehn se dkeho ye bi hogia hia ham krle ge 
    
    t, lcm = solve_crt(t1,mod1,t2,mod2)
    
    if t is None:
        return None 
    
    if t==0:
        t=lcm
        
    return t


def solve ():
    K, N, M, P, Q=map(int,input().split())
    
    
    jaji=[]
    
    for i in range(K) :
        xi, yi =map(int,input().split())
        jaji.append((xi, yi))
        
    sani, sana = jaji[0]
    
    khota = None 
    jaj= -1
    
    
    for i in range(1,K):
        
        xi,yi= jaji[i]
        
        steps= find_steps(sani, sana,xi, yi, N, M, P,Q)
        if steps is None:
            continue 
        if khota is None or steps < khota:
            khota=steps
            jaj=i
            
    ji=find_steps(sani,sana,sani,sana,N,M,P,Q)
    
    if ji is None :
        if khota is None or ji<=khota:
            jaj=0
            
    print(jaj)
    
def main():
    kakag=int(input())
    for __ in range (kakag):
        solve()
        
        
main()

#finally solve this we amazing
        
        

        
  