import sys

input= sys.stdin.readline 


def solve():
    
    N, P , R, K = map(int,input().split())
    
    
    jaja=list(map(int,input().split()))
    
    
    ajaaj= P
    
    wineer= 0
     
     
    for alka in jaja:
        ajaaj-= alka
        
        if ajaaj < 0 :
            
            print("nah i'd lose")
            
            return
        
        wineer+=1
        
        if wineer % K ==0:
            
            ajaaj +=R
            
            
    print("nah i'd win")
    
def main():
    
    jaj= int(input())
    
    for _ in range(jaj):
        solve()
        
main()
            
    
